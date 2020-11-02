#include<stdio.h>
#include<math.h>
#include<graphics.h>//s为bmp路径
#include"putbmp.h"
int putbmp(int x, int y, char *s)
{
    FILE *fp;
    long begin, w, h;
    unsigned char k;
    unsigned char r[15],g[15],b[15];
    int min,distence,minnum;
    unsigned char color[256], R, G, B;
    unsigned int i, j, bit;
    
	r[0]=0, g[0]=0, b[0]=0;
	r[1]=0, g[1]=0, b[1]=255;
	r[2]=0, g[2]=255, b[2]=0;
	r[3]=0, g[3]=255, b[3]=255;
	r[4]=255, g[4]=0, b[4]=0;
	r[5]=255, g[5]=0, b[5]=255;
	r[6]=255, g[6]=127, b[6]=0;
	r[7]=168, g[7]=168, b[7]=168;
    r[8]=84,g[8]=84,b[8]=84;
    r[9]=127,g[9]=127,b[9]=255;
    r[10]=127,g[10]=255,b[10]=127;
    r[11]=127,g[11]=255,b[11]=255;
    r[12]=255,g[12]=127,b[12]=127;
    r[13]=255,g[13]=127,b[13]=255;
    r[14]=255,g[14]=255,b[14]=127;
    r[15]=255,g[15]=255,b[15]=255; 
    
    if ((fp = fopen(s, "rb")) == NULL)
    {
        printf("not open");
        return 1;
    }
    fseek(fp, 10l, 0);
    fread(&begin, 4, 1, fp);
    fseek(fp, 18l, 0);
    fread(&w, 4, 1, fp);
    fread(&h, 4, 1, fp);
    fseek(fp, 28l, 0);
    fread(&bit, 2, 1, fp);
    if (bit != 8)
    {
        fclose(fp);
        printf("bit:%d,not 8", bit);
        return 2;
    }
    fseek(fp, 54l, 0);
    for (i = 0; i < 256; i++)
    {
    	min=1000;
        fread(&B, 1, 1, fp);
        fread(&G, 1, 1, fp);
        fread(&R, 1, 1, fp);
        
    	for(j=0;j<16;j++)
        {
        	distence=abs(R-r[j])+abs(G-g[j])+abs(B-b[j]);
        	if(min>distence)
        	{
        		min=distence;
        		minnum=j;
			}
		} 
		
		color[i]=minnum;
		if(R>150&&G<100&&B<100)
			if(G<50&&B<50)
				color[i]=4;
			else
				color[i]=12;
		if(R<100&&G>150&&B<100)
			if(R<50&&B<50)
				color[i]=2;
			else
				color[i]=10;
		if(R<100&&G<100&&B>150)
			if(R<50&&G<50)
				color[i]=1;
			else
				color[i]=9;
      /*if (R < 42)
        {

            color[i] = (B > 84) + 2 * (G > 84);
        }
        else if (R < 126)
        {
            color[i] = 8 + (B > 168) + 2 * (G > 168);
        }
        else if (R < 210)
        {
            color[i] = 4 + (B > 84) + 2 * (G > 60);
        }
        else
        {
            color[i] = 12 + (B > 168) + 2 * (G > 168);
        }*/ 

        fseek(fp, 1, 1);
    }
    for (i = 0; i < h; i++)
    {

        fseek(fp, begin + (w + 3) / 4 * i * 4, 0);

        for (j = 0; j < w; j++)
        {

            fread(&k, 1, 1, fp);
            //if(color[k]!=15) 
            putpixel(x + j, y + h - i - 1, color[k]);
        }
    }
    fclose(fp);
    return 0;
}
