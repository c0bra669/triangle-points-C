#include<stdio.h>
#include<math.h>
#include<stdbool.h>
typedef struct{
    int Xa,Ya,Xb,Yb,Xc,Yc;
}triangle;
double length(int Xa, int Ya, int Xb, int Yb) {
    return sqrt((Xb - Xa) * (Xb - Xa) + (Yb - Ya) * (Yb - Ya));
}

bool tr_check(triangle *t){
    double a,b,c;
    a = length(t->Xa, t->Ya, t->Xb, t->Yb);
    b = length(t->Xa, t->Ya, t->Xc, t->Yc);
    c = length(t->Xb, t->Yb, t->Xc, t->Yc);
    if (a+b>c&&a+c>b&&b+c>a)
    {
        return true;
    }
    return false;
    
}
double tr_area(triangle *t){
    double a,b,c,s;
    a = length(t->Xa, t->Ya, t->Xb, t->Yb);
    b = length(t->Xa, t->Ya, t->Xc, t->Yc);
    c = length(t->Xb, t->Yb, t->Xc, t->Yc);
    s=(a+b+c)/2;
    return sqrt(s*((s-a)*(s-b)*(s-c)));
}
int tr_circumference(triangle *t){
    double a,b,c;
    a = length(t->Xa, t->Ya, t->Xb, t->Yb);
    b = length(t->Xa, t->Ya, t->Xc, t->Yc);
    c = length(t->Xb, t->Yb, t->Xc, t->Yc);
    return a+b+c;
}
int main(int argc, char **argv){
    if(argc !=3){
        printf("Enter two arguments:\n%s path_to_input_file path_to_output_file\nYour arguments:\n",argv[0]);
        for(int i=0;i<argc;i++){
            printf("%s ",argv[i]);
        }
        return 0;
    }
    triangle t;
    FILE * tr_fptr = fopen(argv[2],"w");
    if(tr_fptr==NULL){
        printf("error with writing to %s",argv[1]);
    }
    FILE * fptr = fopen(argv[1],"r");
    if(fptr==NULL){
        printf("error with reading %s",argv[2]);
    }
    int tr_count;
    while (fscanf(fptr,"%d %d %d %d %d %d",&t.Xa,&t.Ya,&t.Xb,&t.Yb,&t.Xc,&t.Yc)!=EOF)
    {
        if(tr_check(&t)){
            tr_count ++;
            fprintf(tr_fptr,"Points: \n Xa: %d Ya: %d Xb: %d Yb:%d Xc: %d Yc: %d \n",t.Xa,t.Ya,t.Xb,t.Yb,t.Xc,t.Yc);
            fprintf(tr_fptr,"Area: %lf\n",tr_area(&t));
            fprintf(tr_fptr,"Circumference: %d\n",tr_circumference(&t));
        }
    }
    fprintf(tr_fptr,"Triangle Count: %d",tr_count);
    fclose(tr_fptr);
    fclose(fptr);
    return 0; 
}
