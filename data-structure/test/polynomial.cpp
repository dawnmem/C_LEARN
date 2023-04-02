 #include<stdio.h>
 #include<time.h>
 #include<math.h>
 #define MAXK 1e8

 clock_t start, stop;
 double duration;

double f1(int n,double a[],double x){
    int i;
    double p=a[0];
    for(i=1;i<=n;i++){
        p+=a[i]*pow(x,i);
    }
    return p;
}

double f2(int n,double a[],double x){
    int i;
    double p=a[n];
    for(i=n;i>0;i--){
        p=a[i-1]+x*p;
    }
    return p;
}

void MyFunction(){
    int n=20;
    double a[]={1.11,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21};
    double x=1.1;
    for(int i=0;i<MAXK;i++){
    //f1(n,a,x);
    f2(n,a,x);
    }
}

 int main(){
    start=clock();
    MyFunction();
    stop=clock();
    duration =((double)(stop-start))/CLOCKS_PER_SEC/MAXK;
    printf("%lf %ld\n",duration,stop-start);
    return 0;
 }