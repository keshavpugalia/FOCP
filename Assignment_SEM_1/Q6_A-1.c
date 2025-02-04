#include <stdio.h>

//Programme to find quadrant's

int main() {
    int x,y;
    printf("Enter X-cordinate :");
    scanf("%d",&x);
    printf("Enter Y-cordinate :");
    scanf("%d",&y);

    if (x>0 && y>0)
    printf("The cordinate point (%d,%d) lies in First-quadrant",x,y);
    else if (x<0 && y>0)
    printf("The cordinate point (%d,%d) lies in Second-quadrant",x,y);
    else if (x<0 && y<0)
    printf("The cordinate point (%d,%d) lies in Third-quadrant",x,y);
    else if (x>0 && y<0)
    printf("The cordinate point (%d,%d) lies in Fourth-quadrant",x,y);
    else 
    printf("The cordinate point (%d,%d) is at origin",x,y);
    return 0;
}