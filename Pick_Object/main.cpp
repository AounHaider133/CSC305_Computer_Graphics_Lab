#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>
#include <math.h>

#define glRGB(x, y, z) glColor3ub((GLubyte)x, (GLubyte)y, (GLubyte)z)

#define SPHERE 1
#define CONE 2
#define CUBE 3
#define TEAPOT 4
#define TORUS 5

GLfloat fAspect;

// Lighting values
GLfloat whiteLight[] = {0.35f, 0.35f, 0.35f, 1.0f};
GLfloat sourceLight[] = {0.65f, 0.65f, 0.65f, 1.0f};
GLfloat lightPos[] = {0.0f, 0.0f, 0.0f, 1.0f};

void RenderScene(void)
{
    // Clear the window with current clearing color
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Save the matrix and do the rotations
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    // Translate the whole scene out and into view
    glTranslatef(0.0f, 0.0f, -300.0f);

    // Initialize the names stack
    glInitNames();
    glPushName(0);

    // Set material color => YELLOW (Sphere)
    glRGB(255, 255, 0);
    glLoadName(SPHERE);
    glutSolidSphere(15.0f, 15, 15);

    // Draw Cone
    glRGB(128, 0, 0);
    glPushMatrix();
    glTranslatef(24.0f, 0.0f, 0.0f);
    glLoadName(CONE);
    glutSolidCone(15.0f, 30.0f, 15, 15);
    glPopMatrix();

    // Draw Cube
    glRGB(128, 128, 255);
    glPushMatrix();
    glTranslatef(60.0f, 0.0f, 0.0f);
    glLoadName(CUBE);
    glutSolidCube(30.0f);
    glPopMatrix();

    // Draw Teapot
    glRGB(0, 0, 255);
    glPushMatrix();
    glTranslatef(100.0f, 0.0f, 0.0f);
    glLoadName(TEAPOT);
    glutSolidTeapot(12.0f);
    glPopMatrix();

    // Draw TORUS
    glRGB(255, 0, 0);
    glPushMatrix();
    glTranslatef(150.0f, 0.0f, 0.0f);
    glLoadName(TORUS);
    glutSolidTorus(10.0, 18.0, 30, 30);
    glPopMatrix();

    // Restore the matrix state => model view matrix
    glPopMatrix();
    glutSwapBuffers();
}

// Identification of object
void ProcessObject(GLuint id)
{
    switch (id)
    {
    case SPHERE:
        MessageBox(NULL, "You clicked the Sphere!", "Info", MB_OK | MB_ICONEXCLAMATION);
        break;
    case CUBE:
        MessageBox(NULL, "You clicked the Cube!", "Info", MB_OK | MB_ICONEXCLAMATION);
        break;
    case CONE:
        MessageBox(NULL, "You clicked the Cone!", "Info", MB_OK | MB_ICONEXCLAMATION);
        break;
    case TEAPOT:
        MessageBox(NULL, "You clicked the Teapot!", "Info", MB_OK | MB_ICONEXCLAMATION);
        break;
    case TORUS:
        MessageBox(NULL, "You clicked the Torus!", "Info", MB_OK | MB_ICONEXCLAMATION);
        break;
    default:
        MessageBox(NULL, "Nothing was clicked on!", "Error", MB_OK | MB_ICONEXCLAMATION);
        break;
    }
}

// Process the selection, which is triggered by a right mouse click at (xPos, yPos)
#define BUFFER_LENGTH 64
void ProcessSelection(int xPos, int yPos)
{
    // Space for selection buffer
    GLuint selectBuff[BUFFER_LENGTH];

    // Hit counter and viewport storage
    GLint hits, viewport[4];

    // Setup selection buffer
    glSelectBuffer(BUFFER_LENGTH, selectBuff);

    // Get the viewport
    glGetIntegerv(GL_VIEWPORT, viewport);

    // Switch to projection and save the matrix
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    // Change the render mode
    glRenderMode(GL_SELECT);

    // Establish new clipping volume to be unit cube around mouse cursor point (xPos, yPos) and extending
    // two pixels in the vertical and horizontal direction
    glLoadIdentity();
    gluPickMatrix(xPos, viewport[3] - yPos, 2, 2, viewport);
    gluPerspective(45.0f, fAspect, 1.0, 425.0);
    // Draw the scene
    RenderScene();

    // Collect the hits
    hits = glRenderMode(GL_RENDER);

    // Process hits
    if (hits > 0)
    {
        GLuint *ptr = selectBuff;
        GLuint minZ = 0xffffffff;
        GLuint *selected = nullptr;
        for (int i = 0; i < hits; i++)
        {
            if (ptr[1] < minZ)
            {
                minZ = ptr[1];
                selected = ptr;
            }
            ptr += 4;
        }
        if (selected)
            ProcessObject(selected[3]);
    }

    // Restore the matrix
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
}

void ChangeSize(int w, int h)
{
    // Prevent a divide by zero
    if (h == 0)
        h = 1;
    // Set viewport to window dimensions
    glViewport(0, 0, w, h);
    // Compute aspect ratio of the window
    fAspect = (GLfloat)w / (GLfloat)h;
    // Set the perspective coordinate system
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, fAspect, 1.0f, 425.0f);
    // Model view matrix reset
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// Mouse callback function to process mouse events
void MouseCallback(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        ProcessSelection(x, y);
    }
}

// Setup the rendering context
void SetupRC()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, whiteLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, sourceLight);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    glEnable(GL_LIGHT0);

    // Set material properties to follow glColor values
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    // Background color
    glClearColor(0.60f, 0.60f, 0.60f, 1.0f);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 300);
    glutCreateWindow("Pick an Object");
    glutReshapeFunc(ChangeSize);
    glutMouseFunc(MouseCallback);
    glutDisplayFunc(RenderScene);
    SetupRC();
    glutMainLoop();
    return 0;
}
