#include <stdio.h>
int main(int argc, char *argv[])
{
    FILE *in, *out; 
    in = fopen(argv[1], "r");
    out = fopen(argv[2], "w");
    char c, b = 'b', w = 'w';
    int i = 0, j = 0;

    c = getc(in);
    while(c != EOF){
        if(c == b){
            while(c == 'b'){
                i++;
                c = getc(in);
            }
            fprintf(out, "%d", i);
            putc(b, out);
            i = 0;

        }
        else if(c == w){
            while(c == 'w'){
                j++;
                c = getc(in);
            }
            fprintf(out, "%d", j);
            putc(w, out);
            j = 0;

        }
        else{ 
            putc(c, out); //para os dois primeiros numeros
            c = getc(in);
        }
    }
    fclose(in);
    fclose(out);

    return 0;
}