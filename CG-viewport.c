#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

int larg = 600;
int alt = 400;
float dx[16] = {0.0};

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
}


void teclado (unsigned char tecla, int x, int y){
    int l, c, i = 0;
    y = alt - y; //foi necessário inverter o valor de y, pois y = 0 na borda de cima
    switch (tecla){
        case '-':
            for(l = 0; l < 4; l++){
                for(c = 0; c < 4; c++){
                    if(((x > ((larg*c)/4)) && x < (((larg*c)/4) + larg/4)) && (y > ((alt*l)/4) && y < (((alt*l)/4) + alt/4))){
                        dx[i] = dx[i] - 0.1;
                        glutPostRedisplay();
                        return;
                    }
                    i++;
                }
            }

        case '+':
            for(l = 0; l < 4; l++){
                for(c = 0; c < 4; c++){
                    if(((x > ((larg*c)/4)) && x < (((larg*c)/4) + larg/4)) && (y > ((alt*l)/4) && y < (((alt*l)/4) + alt/4))){
                        dx[i] = dx[i] + 0.1;
                        glutPostRedisplay();
                        return;
                    }
                    i++;
                }
            }

    }
}


void figura (float r, float g, float b, float dx){
    float t, x, y;
    glColor3f(r, g, b);
    glLoadIdentity();
    glTranslatef(dx, 0.0, 0.0);
    t = 0.0;
    glBegin(GL_POLYGON);
        while (t < 2*3.14){
            x = 0 + 0.5*cos(t);
            y = 0 + 0.9*sin(t);
            glVertex2f(x,y);
            t += 0.1;
        }
    glEnd();
}

void desenha(){
    int l, c, i = 0;
    float x = 0.0;
    glClear(GL_COLOR_BUFFER_BIT);

    for(l = 0; l < 4; l++){
        for(c = 0; c < 4; c++){
            glViewport((larg*c)/4, (alt*l)/4, larg/4, alt/4);
            figura(0, x, x, dx[i]);
            x+=0.062;
            i++;
        }
    }
    glFlush();
}

int main(int argc, char **argv){

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (larg, alt);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Prática I - Victor Duarte");
    init();
    glutKeyboardFunc(teclado);
    glutDisplayFunc(desenha);
    glutMainLoop();

    return 0;
}
