// Roboflare: line follower and object detection

int L2 = 8; 
int L1 = 10;
int M  = 2;
int R1 = 12;
int R2 = 13;
int lmotfwd = 5;
int lmotrev = 4;
int rmotfwd = 7;
int rmotrev = 6;
int lenable = 3;
int renable = 9;
int turn = 0;
int E,W,S,N;
int dir = E;
int x=-1,y=0;
void setup()//assign pins {
    Serial.begin(9600);//to check 
    /*set the variable for input and output*/ pinMode(L2,INPUT);
    pinMode(L1,INPUT);
    pinMode(M,INPUT);
    pinMode(R1,INPUT);
    pinMode(R2,INPUT);
    pinMode(lmotfwd,OUTPUT);
    pinMode(lmotrev,OUTPUT);
    pinMode(rmotfwd,OUTPUT);
    pinMode(rmotrev,OUTPUT);
}

void turnright()
{
    digitalWrite(lmotfwd,LOW);
    digitalWrite(rmotfwd,LOW);
    digitalWrite(lmotrev,LOW);
    digitalWrite(rmotrev,LOW);
    while(!(digitalRead(L2)== HIGH && digitalRead(R2)== HIGH && digitalRead(R1)==HIGH))
    {
       digitalWrite(lmotfwd,50);
       digitalWrite(rmotfwd,LOW);
       digitalWrite(lmotrev,LOW);
       digitalWrite(rmotrev,LOW);
    }
    
}

void turnleft()
{
    digitalWrite(lmotfwd,LOW);
    digitalWrite(rmotfwd,LOW);
    digitalWrite(lmotrev,LOW);
    digitalWrite(rmotrev,LOW);
    while(!(digitalRead(L2)== HIGH && digitalRead(R2)== HIGH && digitalRead(L1)==HIGH))
    {
      digitalWrite(lmotfwd,LOW);
      digitalWrite(rmotfwd,50);
      digitalWrite(lmotrev,LOW);
      digitalWrite(rmotrev,LOW);
    }
}
/
void loop() {// always run

    if(digitalRead(L2)==HIGH/*(white beneath)*/ && digitalRead(R2)==HIGH)
    {
            if(digitalRead(M)==LOW/*(black beneath)*/  && digitalRead(L1)==HIGH && digitalRead(R1)==HIGH)
            {
                // move forward
                digitalWrite(lmotfwd,100/*speed*/ );
                digitalWrite(rmotfwd,100);
                digitalWrite(lmotrev,LOW);
                digitalWrite(rmotrev,LOW);
            }
            else if(digitalRead(L1)==LOW)
            {
              
                // take left
                digitalWrite(lmotfwd,LOW);
                digitalWrite(rmotfwd,50);
                digitalWrite(lmotrev,LOW);
                digitalWrite(rmotrev,LOW);
            }
            else if(digitalRead(R1)==LOW)
            {
                // take right
                digitalWrite(lmotfwd,50);
                digitalWrite(rmotfwd,LOW);
                digitalWrite(lmotrev,LOW);
                digitalWrite(rmotrev,LOW);
            }
            else if(digitalRead(M)==HIGH && digitalRead(L1)==HIGH && digitalRead(R1)==HIGH)
            {
                  digitalWrite(lmotfwd,30);
                  digitalWrite(rmotfwd,30);
                  digitalWrite(lmotrev,LOW);
                  digitalWrite(rmotrev,LOW);
               
            }
            
    }
    else if(digitalRead(L2)==LOW && digitalRead(L1)==LOW && digitalRead(R2)==HIGH)
    {
          // 90 degree left turn
          if(dir == E)
           {
                  dir = N;
                  x = x + 1;
           }
           else if(dir == W)
           {
                  dir = S;
                  x = x - 1;
           }
           else if(dir == N)
           {
                  dir = W;
                  y = y - 1;
           }
           else if(dir == S)
           {
                  dir = E;
                  y = y + 1;
           }
          digitalWrite(lmotfwd,LOW);
          digitalWrite(rmotfwd,LOW);
          digitalWrite(lmotrev,LOW);
          digitalWrite(rmotrev,LOW);
          while(!(digitalRead(L2)== HIGH && digitalRead(R2)== HIGH && digitalRead(L1)==HIGH))
          {
           digitalWrite(lmotfwd,LOW);
           digitalWrite(rmotfwd,50);
           digitalWrite(lmotrev,LOW);
           digitalWrite(rmotrev,LOW);
          }          
    }
    else if(digitalRead(R2)==LOW && digitalRead(R1)==LOW && digitalRead(L2)==HIGH)
    {
          // 90 degree right turn
          if(dir == E)
           {
                  dir = S;
                  x = x + 1;
           }
           else if(dir == W)
           {
                  dir = N;
                  x = x - 1;
           }
           else if(dir == N)
           {
                  dir = E;
                  y = y + 1;
           }
           else if(dir == S)
           {
                  dir = W;
                  y = y - 1;
           }
          digitalWrite(lmotfwd,LOW);
          digitalWrite(rmotfwd,LOW);
          digitalWrite(lmotrev,LOW);
          digitalWrite(rmotrev,LOW);
          while(!(digitalRead(L2)== HIGH && digitalRead(R2)== HIGH && digitalRead(R1)==HIGH))
          {
           digitalWrite(lmotfwd,50);
           digitalWrite(rmotfwd,LOW);
           digitalWrite(lmotrev,LOW);
           digitalWrite(rmotrev,LOW);
          }
          
    }
    else if(digitalRead(L1)==LOW && digitalRead(L2)==LOW && digitalRead(M)==LOW && digitalRead(R1)==LOW && digitalRead(R2)==LOW)
    {
        // Decision point
        if(dir == E)
        {
            turnright();
            dir = S;
            x = x + 1;
        }
        else if(dir == W)
        {
            turnleft();
            dir = S;
            x = x - 1;
        }
        else if(dir == N)
        {
            turnright();
            dir = E;
            y = y - 1;
        }
        else if(dir == S)
        {
            turnleft();
            dir = E;
            y = y + 1;
        }
    }
    
}
