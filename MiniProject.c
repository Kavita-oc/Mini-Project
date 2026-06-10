#include<stdio.h>
#include<math.h>

typedef struct{
    int type;
    int x1;
    int x2;
    int x3;
    int y1;
    int y2;
    int y3;
    int radius;
}Shape;

void draw_circle(char picture[24][80], Shape circle);
void draw_rectangle(char picture[24][80], Shape rectangle);
void draw_triangle(char picture[24][80], Shape triangle);
void draw_line(char picture[24][80], int y1, int y2, int x1, int x2);
void display_picture(char picture[24][80]);
void clear_picture(char picture[24][80]);
void redraw(char picture[24][80], Shape shape[], int count);

int main(){
    char picture[24][80];
    for(int i=0; i<24; i++){
        for(int j=0; j<80; j++){
            picture[i][j] = '_';
        }
    }

    Shape shape[100];
    int n=0, i=0, shape_type=0;
    while(1){
        printf("2D Graphics Editor\n");
        printf("Canvas size: 80 x 24\n");
        printf("1. Add object\n");
        printf("2. Delete object\n");
        printf("3. Modify object\n");
        printf("4. Display picture\n");
        printf("5. List objects\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &n);

        if(n==0){
            // display_picture(picture);
            printf("Goodbye.\n");
            break;
        }
        else if(n==1){
            printf("Choose shape type:\n");
            printf("1. Line\n");
            printf("2. Rectangle\n");
            printf("3. Circle\n");
            printf("4. Triangle\n");
            printf("Enter shape type: ");
            scanf("%d", &shape_type);
            shape[i].type = shape_type;
            switch(shape_type){
                case 1:
                printf("Enter x1 y1 x2 y2: ");
                scanf("%d %d %d %d", &shape[i].x1, &shape[i].y1, &shape[i].x2, &shape[i].y2);
                draw_line(picture, shape[i].y1, shape[i].y2, shape[i].x1, shape[i].x2);
                break;
                case 2:
                printf("Enter top-left x y and bottom-right x y: ");
                scanf("%d %d %d %d", &shape[i].x1, &shape[i].y1, &shape[i].x2, &shape[i].y2);
                draw_rectangle(picture, shape[i]);
                break;
                case 3:
                printf("Enter center x y and radius: ");
                scanf("%d %d %d", &shape[i].x1, &shape[i].y1, &shape[i].radius);
                draw_circle(picture, shape[i]);
                break;
                case 4:
                printf("Enter x1 y1 x2 y2 x3 y3: ");
                scanf("%d %d %d %d %d %d", &shape[i].x1, &shape[i].y1, &shape[i].x2, &shape[i].y2, &shape[i].x3, &shape[i].y3);
                draw_triangle(picture, shape[i]);
                break;
                default:
                    printf("Invalid shape type.\n");
                    continue;
            }
            printf("Object added with index %d.\n", i);
            i++;
        }
        else if(n == 2){
            int index;

            printf("Enter object index to delete: ");
            scanf("%d", &index);

            if(index >= 0 && index < i)
            {
                for(int j = index; j < i - 1; j++)
                {
                    shape[j] = shape[j + 1];
                }

                i--;

                clear_picture(picture);
                redraw(picture, shape, i);

                printf("Object deleted.\n");
            }
            else
            {
                printf("Invalid index.\n");
            }
        }
        else if(n == 3){
            int index;

            printf("Enter object index to modify: ");
            scanf("%d", &index);

            if(index >= 0 && index < i){
                switch(shape[index].type){
                case 1:
                    printf("Enter new x1 y1 x2 y2: ");
                    scanf("%d %d %d %d",
                        &shape[index].x1,
                        &shape[index].y1,
                        &shape[index].x2,
                        &shape[index].y2);
                    break;

                case 2:
                    printf("Enter new top-left x y and bottom-right x y: ");
                    scanf("%d %d %d %d",
                        &shape[index].x1,
                        &shape[index].y1,
                        &shape[index].x2,
                        &shape[index].y2);
                    break;

                case 3:
                    printf("Enter new center x y and radius: ");
                    scanf("%d %d %d",
                        &shape[index].x1,
                        &shape[index].y1,
                        &shape[index].radius);
                    break;

                case 4:
                    printf("Enter new x1 y1 x2 y2 x3 y3: ");
                    scanf("%d %d %d %d %d %d",
                        &shape[index].x1,
                        &shape[index].y1,
                        &shape[index].x2,
                        &shape[index].y2,
                        &shape[index].x3,
                        &shape[index].y3);
                    break;
            }

                clear_picture(picture);
                redraw(picture, shape, i);

                printf("Object modified.\n");
        }
    else
    {
        printf("Invalid index.\n");
    }
}

else if(n==4){
    display_picture(picture);
}
        else if(n == 5){
            printf("\n--- List of Objects ---\n");
            printf("Index | Type       | Coords\n");
            printf("------|------------|--------------------------\n");

    for(int j = 0; j < i; j++)
    {
        printf("%-6d| ", j);

        switch(shape[j].type)
        {
            case 1:
                printf("%-10s| ", "Line");
                printf("(%d,%d) , (%d,%d)\n",
                       shape[j].x1, shape[j].y1,
                       shape[j].x2, shape[j].y2);
                break;

            case 2:
                printf("%-10s| ", "Rectangle");
                printf("(%d,%d) - (%d,%d)\n",
                       shape[j].x1, shape[j].y1,
                       shape[j].x2, shape[j].y2);
                break;

            case 3:
                printf("%-10s| ", "Circle");
                printf("Center:(%d,%d), R:%d\n",
                       shape[j].x1, shape[j].y1,
                       shape[j].radius);
                break;

            case 4:
                printf("%-10s| ", "Triangle");
                printf("(%d,%d),(%d,%d),(%d,%d)\n",
                       shape[j].x1, shape[j].y1,
                       shape[j].x2, shape[j].y2,
                       shape[j].x3, shape[j].y3);
                break;
        }
    }
    printf("-------------------------------------\n");
}

    }
}

void draw_circle(char picture[24][80], Shape circle){
    int x = circle.x1;
    int y = circle.y1;
    int r = circle.radius;
    for(int i=0; i<24; i++){
        for(int j=0; j<80; j++){
            int d = (j-x)*(j-x) + (i-y)*(i-y);
            float dist = sqrt(d);
            if(dist >= r - 0.5 && dist <= r + 0.5){
                picture[i][j] = '*';
            }
        }
    }
}

void draw_rectangle(char picture[24][80], Shape rectangle){
    int min_x = rectangle.x1 < rectangle.x2 ? rectangle.x1 : rectangle.x2;
    int max_x = rectangle.x1 > rectangle.x2 ? rectangle.x1 : rectangle.x2;
    int min_y = rectangle.y1 < rectangle.y2 ? rectangle.y1 : rectangle.y2;
    int max_y = rectangle.y1 > rectangle.y2 ? rectangle.y1 : rectangle.y2;

    if(min_x < 0) min_x = 0;
    if(max_x > 79) max_x = 79;
    if(min_y < 0) min_y = 0;
    if(max_y > 23) max_y = 23;

   for(int i=min_x;i<=max_x;i++){
    for(int j=min_y;j<=max_y;j++){
        if(i==min_x || i==max_x || j==min_y || j==max_y){
            picture[j][i]='*';
        }
    }
   }
}



    void draw_line(char picture[24][80], int y1, int y2, int x1, int x2){
        if(x1 == x2 && y1 == y2){
            if(x1 >= 0 && x1 < 80 && y1 >= 0 && y1 < 24){
                picture[y1][x1] = '*';
            }
            return;
        }
        int dx=x2-x1;
        int dy=y2-y1;

        int adx=dx<0 ? -dx : dx;
        int ady=dy<0 ? -dy : dy;

        if(adx>=ady){
            if(x1 > x2){
                int tmp;
                tmp = x1; x1 = x2; x2 = tmp;
                tmp = y1; y1 = y2; y2 = tmp;
            }
            float m = (float)(y2-y1)/(x2-x1);
            for(int x=x1;x<=x2;x++){
                int y=(int)(y1+m*(x-x1)+0.5f);
                if(x >= 0 && x < 80 && y >= 0 && y < 24)
                {
                    picture[y][x] = '*';
                }            
            }
        }
        else{
            if(y1 > y2){
                int tmp;
                tmp = x1; x1 = x2; x2 = tmp;
                tmp = y1; y1 = y2; y2 = tmp;
            }
            float m = (float)(x2-x1)/(y2-y1);
            for(int y=y1; y<=y2; y++){
                int x = (int)(x1 + m*(y-y1)+0.5f);
                if(x >= 0 && x < 80 && y >= 0 && y < 24)
                {
                    picture[y][x] = '*';
                }            
            }
        }
    }

void draw_triangle(char picture[24][80], Shape triangle){
    draw_line(picture, triangle.y1, triangle.y2, triangle.x1, triangle.x2);
    draw_line(picture, triangle.y2, triangle.y3, triangle.x2, triangle.x3);
    draw_line(picture, triangle.y3, triangle.y1, triangle.x3, triangle.x1);
}

void display_picture(char picture[24][80]) {
    for(int i = 0; i < 24; i++) {
        for(int j = 0; j < 80; j++) {
            printf("%c", picture[i][j]);
        }
        printf("\n");
    }
}

void clear_picture(char picture[24][80])
{
    for(int i = 0; i < 24; i++)
    {
        for(int j = 0; j < 80; j++)
        {
            picture[i][j] = '_';
        }
    }
}

void redraw(char picture[24][80], Shape shape[], int count)
{
    for(int i = 0; i < count; i++)
    {
        if(shape[i].type == 1)
        {
            draw_line(picture,
                      shape[i].y1, shape[i].y2,
                      shape[i].x1, shape[i].x2);
        }

        else if(shape[i].type == 2)
        {
            draw_rectangle(picture, shape[i]);
        }

        else if(shape[i].type == 3)
        {
            draw_circle(picture, shape[i]);
        }

        else if(shape[i].type == 4)
        {
            draw_triangle(picture, shape[i]);
        }
    }
}