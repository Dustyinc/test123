/* Organisation und Architektur von Rechnern -- Sommersemester 2014
 *   Blatt 1, Aufgabe 1
 *   Timm-Oliver Stoo�  -   stu116914@mail.uni-kiel.de
 */

#include <stdio.h>
#include <stdlib.h>



                                         /* Datenstruktur f�r komplexe Zahlen */
typedef struct s_complex {
    double re;
    double im;
} complex;

                                         /* Berechnet das n�chste Folgenglied */
                                         /* und �berschreibt das �bergebene mit dem N�chsten */
void compute_next(complex *z, complex *c) {

    double re, im;

    re = z->re * z->re - z->im * z->im * z->im + c->re;
    im = 2 * z->re * z->im + c->im;
    z->re = re;
    z->im = im;

}
                                         /* Berechnet, ob die Folge beschr�nkt ist  */
                                         /* R�ckgabe 1 bei vermutlich beschr�nkt    */
                                         /* R�ckgabe 0 sonst                        */
int bounded_sequence(complex *c) {

    int i; double condition;
    complex z;
    z.re = 0;
    z.im = 0;

    for (i = 0; i < 301; i++) {
        compute_next(&z, c);
        condition = z.re * z.re + z.im * z.im;
        if (condition > 4) {
            return 0;
        }
    }
    return 1;
}

                                         /* Zeichnet eine Mandelbrot-Menge                        */
                                         /* Standm�ssig Weite 80, H�he 30                         */
                                         /* Es kann Weite und H�he als Parameter �bergeben werden */
int main(int argn, char *argv[]) {

    int i, j;
    int w, h;
    complex c;
                                      /* Breite und H�he der Ausgabe setzen             */
    if (argn == 1) {
        w = 80;                       /* default, wenn keine Parameter �bergeben wurden */
        h = 30;
    }
    else {
        if (argn == 3) {              /* entspechend den Paramtern setzen, wenn 2 Parameter �bergeben wurden */
            w = atoi(argv[1]);
            h = atoi(argv[2]);
        }
        else {                        /* wenn eine falsche Anzahl von Parametern �bergeben wurde */
            printf("Falsche Anzahl von Parametern!\n");
            return -1;
        }
    }
    printf("Mandelbrot-Menge mit H�he = %d und Breite = %d\n",w,h);
    printf("\n");
                                      /* Schleife, um die Mandebrot-Menge zu zeichnen */
    for (i = 1; i <= h; i++) {
        for (j = 1; j <= w; j++) {
            c.re = (double) 3 * j / w - 2;
            c.im = (double) 2 * i / h - 1;
            if (bounded_sequence(&c)) {        /* beschr�nktes Folgenglied gibt ein '+' */
                    printf("+");
            }
            else {                             /* sonst ein Leerzeichen                 */
                    printf(" ");
            }

        }
    }
    printf("\n");

    return 0;
}









