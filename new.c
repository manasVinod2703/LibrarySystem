#include<stdio.h>


struct car {
    char name[20];
    int speed;
};

int main(){

    FILE * out = fopen("data.txt","ab");
    struct car c1;

    printf("Enter car name: ");
    scanf("%s",c1.name);
    printf("Enter speed: ");
    scanf("%d",&c1.speed);

    fwrite(&c1,sizeof(struct car),1,out);

    fclose(out);

    FILE * in = fopen("data.txt","rb");
    struct car c;
    int count = 0;
    
    while(fread(&c, sizeof(struct car),1,in)){
        printf("Car: %s, speed: %d\n",c.name,c.speed);
        count++;
    }

    printf("The total number of cars is : %d",count);
    

    fclose(in);



    



    return 0;

}