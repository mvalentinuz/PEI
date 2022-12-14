#include "expositor.h"

void Expositor::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(0, 0, 0, 0);
}

void Expositor::resizeGL(int ancho, int alto)
{
    glViewport(0, 0, ancho, alto);
}

void Expositor::paintGL()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width(), 0, height(), -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);

    float relAncho = ((float)width())  / ((float)imagen.getColumnas());
    float relAlto  = ((float)height()) / ((float)imagen.getFilas());
    escala = 1.0f;
    desplx = 0.0f;
    desply = 0.0f;

    if(relAncho < relAlto)
    {
        escala = relAncho;
        desply = (height() - imagen.getFilas()*escala)*0.5f;
    }
    else
    {
        escala = relAlto;
        desplx = (width() - imagen.getColumnas()*escala)*0.5f;
    }
    exponer();

    if(mostrarHistograma)
    {
        graficarHistograma();
    }
}

void Expositor::keyPressEvent(QKeyEvent *evento)
{
    bool imagenAnterior = evento->modifiers() & Qt::ControlModifier and evento->key() == Qt::Key_Left;
    if(imagenAnterior)
    {
        gestor->cambiarArchivoActual(false);
        gestor->leerArchivo(&imagen);
        editor.setImagen(&imagen);
        analizador.setImagen(&imagen);
        update();
    }

    bool imagenSiguiente = evento->modifiers()&Qt::ControlModifier && evento->key() == Qt::Key_Right;
    if(imagenSiguiente)
    {
        gestor->cambiarArchivoActual(true);
        gestor->leerArchivo(&imagen);
        editor.setImagen(&imagen);
        analizador.setImagen(&imagen);
        update();
    }

    bool verHistograma = evento->modifiers() & Qt::ControlModifier && evento->key() == Qt::Key_H;
    if(verHistograma)
    {
        if(mostrarHistograma == false)
        {
            analizador.analizar();
            analizador.generarDatosDeHistograma();
            mostrarHistograma = true;
            update();
        }
        else
        {
            cout<<"Error: Ya se esta mostrando el histograma."<<endl;
        }
    }

    bool almacenarArchivo = evento->modifiers() & Qt::ControlModifier && evento->key() == Qt::Key_G;
    if(almacenarArchivo)
    {

    }

    bool aplicarLUT1 = evento->modifiers() & Qt::ControlModifier && evento->key() == Qt::Key_1;
    if(aplicarLUT1)
    {
        editor.pseudocolorear("..//PEI//grupo_luts//Turbo.lut");
        update();
    }

    bool aplicarLUT2 = evento->modifiers() & Qt::ControlModifier && evento->key() == Qt::Key_2;
    if(aplicarLUT2)
    {
        editor.pseudocolorear("..//PEI//grupo_luts//glow.lut");
        update();
    }

    bool aplicarSuavizado = evento->modifiers() & Qt::ControlModifier && evento->key() == Qt::Key_S;
    if(aplicarSuavizado)
    {
        editor.aplicarPasaBajos();
        update();
    }

    bool aplicarMediana = evento->modifiers() & Qt::ControlModifier && evento->key() == Qt::Key_M;
    if(aplicarMediana)
    {
        editor.aplicarMediana();
        update();
    }

    bool ajustarContraste = evento->modifiers() & Qt::ControlModifier && evento->key() == Qt::Key_C;
    if(ajustarContraste)
    {
        editor.ajustarContraste();
        update();
    }

    bool subirBrillo = evento->modifiers() & Qt::ControlModifier && evento->key() == Qt::Key_Plus;
    if(subirBrillo)
    {
        editor.ajustarBrillo(10);
        update();
    }

    bool bajarBrillo = evento->modifiers() & Qt::ControlModifier && evento->key() == Qt::Key_Minus;
    if(bajarBrillo)
    {
        editor.ajustarBrillo(-10);
        update();
    }

    bool binarizar = evento->modifiers() & Qt::ControlModifier && evento->key() == Qt::Key_B;
    if(binarizar)
    {
        int referencia;
        cout<<"Ingrese la intensidad de referencia: "<<endl;
        cin>>referencia;
        editor.binarizar(referencia);
        update();
    }

    bool aplicarNegativo = evento->modifiers() & Qt::ControlModifier && evento->key() == Qt::Key_N;
    if(aplicarNegativo)
    {
        editor.aplicarNegativo();
        update();
    }

}

void Expositor::mousePressEvent(QMouseEvent *evento)
{
    bool detectarRegion = (evento->modifiers() & Qt::ControlModifier) and evento->button() == Qt::LeftButton;

    int f = this->mapFromGlobal(QCursor::pos()).x();
    int c = this->mapFromGlobal(QCursor::pos()).y();

    if(detectarRegion)
    {
        f= (f - desplx)/escala;
        c= (c - desply)/escala;

        int tolerancia;
        cout<<"Ingrese la tolerancia a considerar: "<<endl;
        cin>>tolerancia;

        analizador.detectarRegion(f, c, tolerancia);
        editor.colorearSuperficie(f, c, analizador.getRegionDetectada());

        cout<<"El ??rea detectada en unidades de p??xeles es "<<analizador.getAreaMapeada()<<" px."<<endl;

        update();

     }
}


Expositor::Expositor(GestorDeArchivos *pGestor)
{
    gestor = pGestor;
    gestor->leerArchivo(&imagen);
    analizador.setImagen(&imagen);
    editor.setImagen(&imagen);
}

void Expositor::abrirVentana(int ancho, int alto, QApplication *QApp)
{
    resize(ancho, alto);
    show();
    QApp->exec();
}

void Expositor::exponer()
{
    glPushMatrix();
    glTranslatef(desplx, desply, 0.0f);
    glScalef(escala, escala, 1.0f);
    glBegin(GL_QUADS);

    Pixel pixel;

    for(int f=0; f<imagen.getFilas(); f++)
    {
        for(int c=0; c<imagen.getColumnas(); c++)
        {
            pixel=imagen.getPixel(f,c);
            glColor3f((float)pixel.getR()/(float)imagen.getValorMaximo(), (float)pixel.getG()/(float)imagen.getValorMaximo(), (float)pixel.getB()/(float)imagen.getValorMaximo());

            glVertex3i(c+1, imagen.getFilas()-f,0);
            glVertex3i(c, imagen.getFilas()-f,0);
            glVertex3i(c, imagen.getFilas()-f+1,0);
            glVertex3i(c+1, imagen.getFilas()-f+1,0);
        }
    }
    glEnd();
    glPopMatrix();
}

void Expositor::graficarHistograma()
{
    if(imagen.getId()=="P3" || imagen.getId()=="P6")
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glPushMatrix();
        glScalef(width()/256.0f, height()/(analizador.getMayorFrecuenciaModaRGB()*1.0f), 0.0f);
        vector<int> funcionRojos = analizador.getFuncionRojos();
        vector<int> funcionVerdes = analizador.getFuncionVerdes();
        vector<int> funcionAzules = analizador.getFuncionAzules();

        for (unsigned int i=0; i<funcionRojos.size(); i++)
        {
            glBegin(GL_LINE_STRIP);
            {
                glColor3f(1.0, 0.0, 0.0);
                glVertex2i(i, funcionRojos[i]);
                glVertex2i(i+1, funcionRojos[i+1]);
            }
            glEnd();
        }

        for (unsigned int i=0; i<funcionVerdes.size(); i++)
        {
            glBegin(GL_LINE_STRIP);
            {
                glColor3f(0.0, 1.0, 0.0);
                glVertex2i(i, funcionVerdes[i]);
                glVertex2i(i+1, funcionVerdes[i+1]);
            }
            glEnd();
        }

        for (unsigned int i=0; i<funcionAzules.size(); i++)
        {
            glBegin(GL_LINE_STRIP);
            {
                glColor3f(0.0, 0.0, 1.0);
                glVertex2i(i, funcionAzules[i]);
                glVertex2i(i+1, funcionAzules[i+1]);
            }
            glEnd();
        }
        glPopMatrix();
    }
    else
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glPushMatrix();
        glScalef(width()/256.0f, height()/(analizador.getFrecuenciaModa()*1.0f), 0.0f);

        vector<int> funcionIntensidades = analizador.getFuncionIntensidades();
        for (unsigned int i=0; i<funcionIntensidades.size(); i++)
        {
            glBegin(GL_LINE_STRIP);
            {
                glColor3f(1.0, 1.0, 1.0);
                glVertex2i(i, funcionIntensidades[i]);
                glVertex2i(i+1, funcionIntensidades[i+1]);
            }
            glEnd();
        }
        glPopMatrix();
    }
}

Expositor::~Expositor()
{

}
