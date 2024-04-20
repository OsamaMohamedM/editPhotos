// FCAI –OOP Programming– 2023 - Assignment 1
// Program: Filters.cpp
// Purpose: Demonstrate use of bmplip for handling
//           bmp colored and grayscale images,
//           Program load a gray image and store in another file
//          Program load a gray image and store in another file
// Author1: Osama Mohamed Mahmoud  , Id: 20220056 section number=s5
// Author2: Mohamed Ahmed Shawky   , Id: 20220275 section number=s4
// Author3: Youssef Mohamed Hussin , Id: 20221203 section number=s11
// last UpDate:9/10/2023
//Version: 1.0
#include <iostream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"
using namespace std;
unsigned char image[SIZE][SIZE][RGB];// represent each pixel of image as array 2D
unsigned char image2[SIZE][SIZE][RGB];//represent each pixel as of image array 2D
const double pi=3.14159265359;
//declearation of functions
// declaration of function for load the image
void load_Image();// declaration of function for load the image
void convert_to_gray();
void load_anthor_Image();// declaration of function for load_anthor the image
void save_Image();// declaration of function for saave the image,
void convert_Image_To_Black_And_White_filter();// declaration of function for convert_Image_To_Black_And_White_filte
void Invert_Image();// declaration of function for Invert_Image ,
void merge_Image();//declaration of function for merge_Image
void flip_Image();//declaration of function for flip_Image,
void rotate_image90();//declaration of function for Rotate_Image90
void  Rotate_Image180();//declaration of function for Rotate_Image180
void  Rotate_Image270();//declaration of function for Rotate_Image270
void darken_And_Lighten();//declaration of function for darken_And_Lighten(),
void  shrink_image();//declaration of function for shrink_image
void shrink_Quarter_image();//declaration of function for shrink_Quarter_image
void shrink_third_image();//declaration of function for shrink_third_image
void shrink_half_image();//declaration of function for shrink_half_image
void detect_Image_Edges(); // declaration of function detect_Image_Edges
void blur_image();//declaration of function for blur_image
void  Shuffle_Image();//declaration of function for Shuffle_Image
bool select_Filter();//declaration of function for select_Filter
void mirror_Image();// declaration of function mirror 1/2 image
void corp_Image(); // declaration of function corp_Image
void skew_image_horizontally();//declaration of function for skew_image_horizontally
void skew_image_vertically();//declaration of function for skew_image_vertically
void   enlarge_image ();
bool select_Filter();//declaration of function for select_Filter
int main()
{
    cout<<"Hello Broo \n";
    while(true)
    {
        if(!select_Filter())break;
    }
    cout<<"Good bye And come again";
}
// definition of function for select filter the image
bool select_Filter() {
    cout << "Please Choose the number of your filter\n";
    cout << "1- Black and White Filter\n";
    cout << "2- Invert Image\n";
    cout << "3- Merge Images\n";
    cout << "4- Flip Image\n";
    cout << "5- Rotate Image\n";
    cout << "6- Darken and Lighten Image\n";
    cout << "7- Detect Image Edges\n";
    cout << "8- enlarge Image\n";
    cout << "9- shrink Image\n";
    cout << "a- Mirror Image\n";
    cout << "b- Shuffle_Image\n";
    cout << "c- Blur Image\n";
    cout << "d- Crop Image\n";
    cout << "e- Skew Horizontally \n";
    cout << "f- Skew Vertically\n";
    cout << "0- Exit\n";
    char choose;
    cin >> choose;
    if (isalpha(choose))choose = tolower(choose);
    if (choose == '1') {
        load_Image();
        convert_Image_To_Black_And_White_filter();
        save_Image();
        return true;
    }
    else if(choose=='2')
    {
        load_Image();
        Invert_Image();
        save_Image();
        return true;

    }
    else if (choose == '3') {
        load_Image();
        merge_Image();
        save_Image();
        return true;
    } else if (choose == '4') {
        load_Image();
        flip_Image();
        save_Image();
        return true;

    }
    else if(choose=='5')
    {
        load_Image();
        cout<<"choose the degree\n";
        cout<<"1- 90 2- 180 3- 270";
        int chooise;cin>>chooise;
        if(chooise==1|| chooise==90)
        {

            rotate_image90();
            save_Image();
        }
        else if( chooise==2 || chooise==180)
        {
            Rotate_Image180();
            save_Image();
        }
        else if(chooise==3 ||chooise==270)
        {

            Rotate_Image180();
            save_Image();
        }
        else {
            cout << "Wrong input";
        }
        return true;
    }
    else if (choose == '6') {
        load_Image();
        darken_And_Lighten();
        save_Image();
        return true;
    }
    else if(choose == '7'){
        load_Image();
        detect_Image_Edges();
        save_Image();
        return true;
    }

    else if (choose == '8') {
        load_Image();
        enlarge_image();
        save_Image();
        return true;
    }
    else if (choose == '9') {
        load_Image();
        shrink_image();
        save_Image();
        return true;
    }
    else if(choose == 'a'){
        load_Image();
        mirror_Image();
        save_Image();
        return true;
    }
    else if (choose == 'b') {
        load_Image();
        Shuffle_Image();
        save_Image();
        return true;
    }
    else if (choose == 'c') {
        load_Image();
        blur_image();
        save_Image();
        return true;
    }
    else if(choose == 'd'){
        load_Image();
        corp_Image();
        save_Image();
        return true;
    }
    else if (choose == 'e') {
        load_Image();
        skew_image_horizontally();
        return true;
    }
    else if (choose == 'f') {
        load_Image();
        skew_image_vertically();
        return true;
    }
    else if (choose == '0') {
        return false;
    }
}
// definition of function for load the image
void load_Image()
{
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    // Add to image file name .bmp extension and load image
    strcat(imageFileName, ".bmp");
    readRGBBMP(imageFileName, image);
}
void convert_to_gray()
{
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {

                int gray=0.3*(image[i][j][0])+image[i][j][1]*0.59+image[i][j][2]*0.11;
                image[i][j][0]=gray;
                image[i][j][1]=gray;
                image[i][j][2]=gray;


        }
    }
}
// definition of function for load_anthor_Image the image
void load_anthor_Image()
{
    char imageFileName2[100];

    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName2;

    // Add to image file name .bmp extension and load image
    strcat(imageFileName2, ".bmp");
    readRGBBMP(imageFileName2, image2);
}
// definition of function for save the image
void save_Image() {
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to image file name .bmp extension and load image
    strcat(imageFileName, ".bmp");
    writeRGBBMP(imageFileName, image);
}
// definition of function for convert Image To_Black And White Image  the image
void convert_Image_To_Black_And_White_filter()
{
// 2 nested loops to loop in each pixel
  convert_to_gray();
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++) {
            for (int x = 0; x < RGB; x++) {
                if (image[i][j][x] > 127) {
                    // convert all pixels that greater than 127(level of gray is low) to White
                    image[i][j][x] = 255;
                } else {
                    // convert all pixels that less than 127(level of gray is high) to Black
                    image[i][j][x] = 0;
                }
            }
        }
    }
}
// definition of function for invert the image
// definition of function for invert the image
void Invert_Image() {
    // 2 nested loops to loop in each pixel
    convert_to_gray();
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            // convirt each pixel to opposite level of brightness
            for(int x=0;x<RGB;x++) {
                image[i][j][x] = 255 - image[i][j][x];

            }
        }
    }
}
// definition of function for merge the image
void merge_Image() {
    // here i recive the second picture and then the 255 *255 of the picture
    // i compare each index of the two matrices and find the mean of the
    // two indecies and replcae it with the value of the index at the first picture
    // and it means that all the changes will happen at the first picture
    load_anthor_Image();
    // 2 nested loops to loop in each pixel
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            for(int k=0;k<RGB;k++) {
                int x = (image[i][j][k] + image2[i][j][k]) / 2;//get avreage of pixel
                image[i][j][k] = x;
            }
        }
    }
}
// definition of function for flip the image
void flip_Image()
{
    cout<<"How do you want to flip image\n";
    cout<<"1- horizontally\n";
    cout<<"2- vertically\n";
    char choose;cin>>choose;
    if(choose=='1') {
        // 2 nested loops to loop in each pixel
        for (int i = 0; i < SIZE; i++) {
            // reverse elements of every row.
            for (int j = 0; j < SIZE / 2; j++) {
                for(int x=0;x<RGB;x++) {
                    swap(image[j][i][x], image[SIZE - 1 - j][i][x]);
                }
            }
        }
    }
    else if(choose=='2')
    {
        // 2 nested loops to loop in each pixel
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE / 2; j++) {
                for(int x=0;x<RGB;x++) {
                    swap(image[i][j][x], image[i][SIZE - 1 - j][x]);//  reverse elements of every column.
                }
            }
        }
    }
}
//definition of function for Rotate_Image180  the image
void  Rotate_Image180() {
    // 2 nested loops to loop in each pixel
    // and copy in anther array
    unsigned char image3[SIZE][SIZE][RGB];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            for(int x=0;x<RGB;x++) {
                image3[i][j][x] = image[i][j][x];
            }
        }
    }
    int a=0,b=0;
    // rotate the image by copies the elements of image2 back to image in reverse order
    for (int i=SIZE-1; i>=0; i--) {
        for (int j = SIZE-1; j>=0; j--) {
            for(int x=0;x<RGB;x++) {
                image[a][b][x] = image3[i][j][x];
            }
            b++;
        }
        b=0;
        a++;
    }
}
//definition of function for Rotate_Image270 the image
void  Rotate_Image270() {
    // 2 nested loops to loop in each pixel
    // and copy in another array
    unsigned char image3[SIZE][SIZE][RGB];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            for(int x=0;x<RGB;x++) {
                image3[i][j][x] = image[i][j][x];
            }
        }
    }
    // rotate the image by reverse each row

    int a=0;
    for (int j=SIZE-1; j>=0; j--) {
        for (int i =0; i<SIZE; i++) {
            for(int x=0;x<RGB;x++) {
                image[a][i][x] = image3[i][j][x];
            }
        }
        a++;
    }
}
// definition of function for darken And Lighten the image
void darken_And_Lighten() {
    // here i ask the user if he wants to lighten or darken the picture
    // then if he wants to lighten the picture i increase the value of each
    // index by (255-it's value)/2,
    // and if i want to darken then i reduce the value of each index by
    // (it's value)/2.
    cout<<"Do you want to (d)arken or (l)ighten ?"<<endl;
    char a;cin>>a;
    a=tolower(a);
    // 2 nested loops to loop in each pixel
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            if (a == 'l') {
                for(int x=0;x<RGB;x++) {
                    image[i][j][x] += (255 - image[i][j][x]) / 2;
                }
            }
            else {
                for(int x=0;x<RGB;x++) {
                    image[i][j][x]-=(image[i][j][x])/2;
                }
                 }
        }
    }
}
//definition of function for Rotate_Image270 the image
void rotate_image90() {
    // copy image in reverse order
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            for(int x=0;x<RGB;x++) {
                image2[i][j][x] = image[j][i][x];
            }
        }
    }
    int a=0;
    // load the image
    for (int i=0; i<SIZE; i++) {
        for (int j = SIZE-1; j>=0; j--) {
            for(int x=0;x<RGB;x++) {
                image[i][a][x]=image2[i][j][x];
            }
            a++;
        }
        a=0;
    }
}
void detect_Image_Edges() {
    // first i turn the array into black and white then
    //  i take the values of the original picture in another
    // variable array and then compare the values in this variable as next:
    // each pixel in this array if it differents from any pixel around it
    // then i make this pixel black
    //else i make it white
    // 2 nested loops to loop in each pixel
  //  convert_to_gray();
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
           for(int x=0;x<RGB;x++) {
               if (image[i][j][x] > 127)image[i][j][x] = 255;
               else image[i][j][x] = 0;
               image2[i][j][x] = image[i][j][x];
           }
        }
    }
    // 2 nested loops to loop in each pixel
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE-1; j++) {
            for(int x=0;x<RGB;x++) {
                if (image2[i][j][x] != image2[i][j + 1][x] or image2[i][j][x] != image2[i][j - 1][x]
                    or image2[i][j][x] != image2[i + 1][j][x] or image2[i][j][x] != image2[i - 1][j][x])
                    image[i][j][x] = 0;
                else image[i][j][x] = 255;
            }
        }
    }
    convert_to_gray();
    convert_Image_To_Black_And_White_filter();

}
// definition of function for enlarge the image
void   enlarge_image () {
    // take the quarter from user
    cout<<"Enter your quarter: ";
    unsigned char val[SIZE][SIZE][RGB];
    int q; cin>>q;
    int x=0,y=0;
    // to copy the quarter
    switch (q) {
        // frist quarter
        case 1:
            for (int i = 0; i <SIZE/2 ; ++i) {
                for (int j = 0; j <SIZE/2 ; ++j) {
                    for(int k=0;k<RGB;k++) {


                        image2[x][y][k] = image[i][j][k];
                    }
                    y++;
                }
                x++;y=0;
            }
            break;
            // second quarter
        case 2:
            for (int i = 0; i <SIZE/2 ; ++i) {
                for (int j = SIZE/2-1; j <SIZE ; ++j) {
                    for(int k=0;k<RGB;k++) {
                        image2[x][y][k] = image[i][j][k];
                    }
                    y++;
                }
                x++;y=0;
            }
            break;
            // third quarter
        case 3:
            for (int i = SIZE/2-1; i <SIZE; ++i) {
                for (int j = 0; j <SIZE/2 ; ++j) {
                    for(int k=0;k<RGB;k++) {
                        image2[x][y][k] = image[i][j][k];
                    }
                    y++;
                }
                x++;y=0;
            }
            break;
            // fourth quarter
        case 4:
            for (int i = SIZE/2-1; i <SIZE; ++i) {
                for (int j = SIZE/2-1; j <SIZE ; ++j) {
                    for(int k=0;k<RGB;k++) {
                        image2[x][y][k] = image[i][j][k];
                    }
                    y++;
                }
                x++;y=0;
            }
            break;
        default:
            break;

    }
    // to enlarge the input quarter
    int a=0,b=0;
    for (int i = 0; i <SIZE/2 ; ++i) {
        for (int j = 0; j <SIZE/2 ; ++j) {
            for(int k=0;k<RGB;k++)
            {
                image[a][b][k]=image2[i][j][k];
                image[a][b+1][k]=image2[i][j][k];
                image[a+1][b+1][k]=image2[i][j][k];
                image[a+1][b][k]=image2[i][j][k];
            }
            b+=2;

        }
        a+=2;
        if (b>=256)
            b=0;
    }
}

void  shrink_image () {
    // take the dimension from user
    string dimension;
    cout<<"Enter your dimension: ";
    cout<<"1- 1/2\n";
    cout<<"2- 1/3\n";
    cout<<"3- 1/4\n";
    cin>>dimension;
    if(dimension=="1" || dimension=="1/2")
    {
        shrink_half_image();
    }
    else if(dimension=="1/3"|| dimension=="2")
    {
        shrink_third_image();
    }
    else if(dimension=="1/4"|| dimension=="3")
    {
        shrink_Quarter_image();
    }
}
void shrink_half_image(){
    unsigned char val[SIZE][SIZE][RGB];
    memset(val,255,sizeof (val));//make each pixel to white
    // 2 nested loops to loop in each pixel
    for(int i=0,x=0;i<SIZE;i+=2,x++)
    {
        for(int j=0,y=0;j<SIZE;j+=2,y++)
        {
            for(int k=0;k<RGB;k++) {
                int avg = (image[i][j][k] + image[i][j + 1][k] + image[i + 1][j][k] + image[i + 1][j + 1][k]) /
                          4;//take avrege of 4 adjecet pixels
                val[x][y][k] = avg;//assgin avrage to val
            }
        }
    }
    for(int i=0,x=0;i<SIZE;i++) {
        for (int j = 0; j < SIZE; j++) {
            for(int k=0;k<RGB;k++) {
                image[i][j][k]= val[i][j][k];//assgin val to image
            }
        }
    }
}
void shrink_third_image(){
    unsigned char val[SIZE][SIZE][RGB];
    memset(val,255,sizeof (val));//make each pixel to white
    // 2 nested loops to loop in each pixel
    for(int i=0,x=0;i<SIZE;i+=3,x++)
    {
        for(int j=0,y=0;j<SIZE;j+=3,y++)
        {
            for(int k=0;k<RGB;k++) {
                int avg = (image[i][j][k] + image[i][j + 1][k]+ image[i + 1][j][k] + image[i + 1][j + 1][k]
                        + image[i + 2][j][k]+ image[i][j + 2][k]+ image[i + 1][j + 2][k] + image[i + 2][j + 1][k]
                        + image[i + 2][j + 2][k]) /9;//take avrege of 9 adjecet pixels
                val[x][y][k] = avg;//assgin avrage to val
            }
        }
    }
    for(int i=0,x=0;i<SIZE;i++) {
        for (int j = 0; j < SIZE; j++) {
            for(int k=0;k<RGB;k++) {
                image[i][j][k]= val[i][j][k];//assgin val to image
            }
        }
    }
}
void shrink_Quarter_image(){
    unsigned char val[SIZE][SIZE][RGB];
    memset(val,255,sizeof (val));//make each pixel to white
    // 2 nested loops to loop in each pixel
    for(int i=0,x=0;i<SIZE;i+=4,x++)
    {
        for(int j=0,y=0;j<SIZE;j+=4,y++)
        {
            for(int k=0;k<RGB;k++) {
                int avg = (image[i][j][k] + image[i][j + 1][k]+ image[i + 1][j][k] + image[i + 1][j + 1][k]
                        + image[i + 2][j][k]+ image[i][j + 2][k] + image[i + 1][j + 2][k] + image[i + 2][j + 1][k]
                        + image[i + 2][j + 2][k]+image[i][j + 3][k]+image[i + 1][j + 3][k]+image[i + 2][j + 3][k]
                        + image[i + 3][j][k] + image[i + 3][j + 1][k] +image[i + 3][j + 2][k]
                           + image[i + 3][j + 3][k]) / 16;//take avrege of 16 adjecet pixels
                val[x][y][k]= avg;
            }
        }
    }
    for(int i=0,x=0;i<SIZE;i++) {
        for (int j = 0; j < SIZE; j++) {
            for(int k=0;k<RGB;k++) {
                image[i][j][k] = val[i][j][k];//assgin val to image
            }
        }
    }
}
void mirror_Image()
{
    char c;
    cout<<"cout <<Mirror (1)Left, (2)Right, (3)Upper, (4)Down side?\n";
    cin>>c;
    if(c=='1')
    {
        // 2 nested loops to loop in each pixel
        for (int i=0;i<SIZE;i++)
        {
            for(int j=0;j<SIZE;j++)
            {
                for(int k=0;k<RGB;k++) {
                    // mirror left
                    // mirror each pixel
                    // the pixel [0][255] will mirror in pixel [0][0]
                    // the pixel [0][254] will mirror in pixel [0][1]  so on
                    image[i][SIZE - 1 - j][k] = image[i][j][k];
                }
            }
        }
    }
    else if(c=='2')
    {
        // 2 nested loops to loop in each pixel
        for (int i=0;i<SIZE;i++)
        {
            for(int j=0;j<SIZE;j++)
            {
                // mirror right
                // mirror each pixel
                // the pixel [0][0] will mirror in pixel [0][255]
                // the pixel [0][1] will mirror in pixel [0][254]  so on
                for(int k=0;k<RGB;k++) {
                    image[i][j][k] = image[i][SIZE - 1 - j][k];
                }
            }
        }
    }
    else if(c=='3')
    {
        // 2 nested loops to loop in each pixel
        for (int i=0;i<SIZE;i++)
        {
            for(int j=0;j<SIZE;j++)
            {
                // mirror upper
                // mirror each pixel
                // the pixel [255][0] will mirror in pixel [0][0]
                // the pixel [254][0] will mirror in pixel [1][0]  so on
                for(int k=0;k<RGB;k++) {
                    image[SIZE - 1 - j][i][k]= image[j][i][k];
                }
            }
        }
    }
    else
    {
        // 2 nested loops to loop in each pixel
        for (int i=0;i<SIZE;i++)
        {
            for(int j=0;j<SIZE/2;j++)
            {
                // mirror left
                // mirror each pixel
                // the pixel [0][0] will mirror in pixel [255][0]
                // the pixel [1][0] will mirror in pixel [254][0]  so on
                for(int k=0;k<RGB;k++) {
                    image[j][i][k] = image[SIZE - 1 - j][i][k];
                }
            }
        }
    }
}


void  Shuffle_Image() {
    cout<<"Enter your order: ";
    int ord[4];
    // take the order from the user
    for (int & i : ord) {
        cin>>i;
    }
    // copy the original image
    for (int i = 0; i < SIZE ; i++) {
        for (int j = 0; j< SIZE ; j++) {
            for(int k=0;k<RGB;k++) {
                image2[i][j][k] = image[i][j][k];
            }
        }
    }
    int x=0,y=0;
    // to load the new image
    for (int i = 0; i < 4; ++i) {
        if (i==0){
            x=0,y=0;
        }
        if (i==1){
            x=0,y=SIZE/2-1;
        }
        if (i==2){
            x=SIZE/2-1;
            y=0;
        }
        if (i==3){
            x=SIZE/2-1;
            y=SIZE/2-1;
        }
        int n=x,m=y;
        // to load the image based on the users order
        switch (ord[i]) {
            case 1:
                for (int j = 0; j <SIZE/2 ; ++j) {
                    for (int k = 0; k <SIZE/2 ; ++k) {
                        for(int z=0;z<RGB;z++) {
                            image[n][m][z] = image2[j][k][z];
                        }
                        m++;
                    }
                    m=y;
                    n++;
                }
                break;
            case 2:
                for (int j = 0; j <SIZE/2 ; ++j) {
                    for (int k = SIZE/2-1; k <SIZE ; ++k) {
                        for(int z=0;z<RGB;z++) {
                            image[n][m][z] = image2[j][k][z];
                        }
                        m++;
                    }
                    m=y;
                    n++;
                }
                break;
            case 3:
                for (int j = SIZE/2-1; j <SIZE ; ++j) {
                    for (int k = 0; k <SIZE/2 ; ++k) {
                        for(int z=0;z<RGB;z++) {
                            image[n][m][z] = image2[j][k][z];
                        }
                        m++;
                    }
                    m=y;
                    n++;
                }
                break;
            case 4:
                for (int j = SIZE/2-1; j <SIZE ; ++j) {
                    for (int k = SIZE/2-1; k <SIZE ; ++k) {
                        for(int z=0;z<RGB;z++) {
                            image[n][m][z] = image2[j][k][z];
                        }
                        m++;
                    }
                    m=y;
                    n++;
                }
                break;

            default:
                break;
        }
    }
}
// definition of function for blur the image
void blur_image() {
    // 2 nested loops to loop in each pixel
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            for (int k = 0; k < RGB; k++) {
                int sum = 0;
                // 2 nested loops to loop in each pixel
                //this loop will make a square of 64 pixel
                for (int x = 0; x < 8; ++x) {
                    for (int y = 0; y < 8; ++y) {
                        sum += image[x + i][y + j][k];
                    }
                }

                // take the average of 64 pixel
                int avg = sum / 64;
                //put the average of this 64 pixels in the middle of the square
                image[i + 3][j + 3][k] = avg;
            }
        }
    }
}

// definition of function for crop the image
void corp_Image()
{
    // Here I take from user the position of pixel
    cout<<"input the row of pixel and it colum (x,y)\n";
    int position_x,position_y;cin>>position_x>>position_y;
    cout<<"input the length and width\n";
    int length,width;cin>>length>>width;// take length and width of sqaure
    int max_x=min(position_x+width,SIZE);//find max point can get right the position
    int min_x=max(position_x-width,0);//find max point can get left the position
    int max_y=min(position_y+length,SIZE);//find max point can get down the position
    int min_y=max(position_y-length,0);//find max point can get upper the position
    // 2 nested loops to loop in each pixel
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            for(int k=0;k<RGB;k++) {
                if ((i <= max_x && i >= min_x) && (j <= max_y && j >= min_y))
                    continue;
                else image[i][j][k]= 255;
            }
        }
    }
}

void skew_image_horizontally(){
    unsigned char val[SIZE][SIZE][RGB];// anthor array to save pixel
    memset(val,255, sizeof(val));//assgin element in the val to value=255
    cout<<"please input angle between 1 45\n";
    double angle ;cin>>angle;//take the angle of user
    if(angle>45 || !angle)return;
    angle*=(pi/180);//convert angle to redian
    double num_pix=tan(angle)*256;//find the number of pixel will be white
    double cmp=256;
    if((angle*(180/pi))!=45)//to void runtime
    {
        cmp=256.0/(256.0-num_pix);//find the number of pixel will be compressed
    }
    for (int i = 0; i < SIZE ; ++i) {
        for (int j = 0; j*cmp < SIZE ; ++j) {
            for(int k=0;k<RGB;k++) {
                val[i][j][k] = image[i][(int) ceil(j * cmp)][k];//compress the image
            }
        }
    }
    unsigned char tmp[SIZE][SIZE][RGB];//decleare a new image
    memset(tmp,255, sizeof(tmp));//make tmp white image
    int shift=ceil(256.0*tan(angle));//find the first pixel whill shift to it
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j+shift<SIZE;j++)
        {
            for(int k=0;k<RGB;k++)
            {
                tmp[i][shift+j][k]=val[i][j][k];
            }


        }
        shift=ceil((256.0-i+1)*tan(angle));
    }
    swap(tmp,image);//swap images
    save_Image();
}

//definition of skew_image_vertically function
void skew_image_vertically(){
    unsigned char val[SIZE][SIZE][RGB];// anthor array to save pixel
    memset(val,255, sizeof(val));//assgin element in the val to value=255
    cout<<"please input angle between 1 45\n";
    double angle ;cin>>angle;//take the angle of user
    if(angle>45 || !angle)return;
    angle*=(pi/180);//convert angle to redian
    double num_pix=tan(angle)*256;//find the number of pixel will be white
    double cmp=256;
    if((angle*(180/pi))!=45)//to void runtime
    {
        cmp=256.0/(256.0-num_pix);//find the number of pixel will be compressed
    }
    for (int i = 0; i < SIZE ; ++i) {
        for (int j = 0; j*cmp < SIZE ; ++j) {
            for(int k=0;k<RGB;k++) {
                val[j][i][k] = image[(int) ceil(j * cmp)][i][k];//compress the image
            }
        }
    }
    unsigned char tmp[SIZE][SIZE][RGB];//decleare a new image
    memset(tmp,255, sizeof(tmp));//make tmp white image
    int shift=ceil(256.0*tan(angle));//find the first pixel whill shift to it
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j+shift<SIZE;j++)
        {
            for(int k=0;k<RGB;k++) {
                tmp[shift + j][i][k] = val[j][i][k];
            }


        }
        shift=ceil((256.0-i+1)*tan(angle));
    }
    swap(tmp,image);//swap images
    save_Image();
}





