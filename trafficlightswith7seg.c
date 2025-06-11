#include <regx51.h>
#define seg P1
sbit e1 = P3^6;
sbit e2 = P3^7;
// 7-segment display encoding for 0-9
char num[] = {0x03,0x9F,0x25,0x0D,0x99,0x49,0x41,0x1F,0x01,0x19};
// Traffic Light Pins
sbit R1 = P2^0; sbit Y1 = P2^1; sbit G1 = P2^2;
sbit R2 = P2^3; sbit Y2 = P2^4; sbit G2 = P2^5;
sbit R3 = P3^0; sbit Y3 = P3^1; sbit G3 = P3^2;
sbit R4 = P3^3; sbit Y4 = P3^4; sbit G4 = P3^5;
// Function Declarations
void delay(int);
void display(int);
void countdown(int);
void main() 
	{
    while(1) 
			{
        // ==== Pole 1 ====
        R1=0; Y1=0; G1=1;  // Green
        R2=1; G2=0; Y2=0;
        R3=1; G3=0; Y3=0;
        R4=1; G4=0; Y4=0;
        countdown(10);

        G1=0; Y1=1;        // Yellow
        countdown(5);
				Y1=0; R1=1;        // Red
        countdown(20);
				// ==== Pole 2 ====
        R2=0; Y2=0; G2=1;
        countdown(10);
        G2=0; Y2=1;
        countdown(5);
        Y2=0; R2=1;
        countdown(20);
        // ==== Pole 3 ====
        R3=0; Y3=0; G3=1;
        countdown(10);
        G3=0; Y3=1;
        countdown(5);
        Y3=0; R3=1;
        countdown(20);
        // ==== Pole 4 ====
        R4=0; Y4=0; G4=1;
        countdown(10);
        G4=0; Y4=1;
        countdown(5);
        Y4=0; R4=1;
        countdown(20);
			}
	}

void countdown(int t) 
	{
    int i, k;
    for(i = t; i >= 0; i--)
		{
			for(k = 0; k < 50; k++)
			{
            display(i);
       }
    }
	}

void display(int n) 
	{
    int d1 = n % 10;
    int d2 = n / 10;

    e1 = 1; e2 = 0; seg = num[d2]; delay(5);
    e1 = 0; e2 = 0; delay(1);
    e1 = 0; e2 = 1; seg = num[d1]; delay(5);
    e1 = 0; e2 = 0; delay(1);
	}

void delay(int a)
	{
    int i;
    for(i = 0; i < a; i++) 
		{
        TMOD = 0x01;
        TL0 = 0x66;
        TH0 = 0xFC;
        TR0 = 1;
        while(TF0 == 0);
        TF0 = 0;
        TR0 = 0;
    }
	}
