int led1 = D6;

void setup() 
{
 
    
    pinMode(led1, OUTPUT);
    

    
    digitalWrite(led1, LOW);

    Particle.subscribe("Deakin_RIOT_SIT210_Photon_Buddy", myHandler, ALL_DEVICES);
}

void loop() {

    for(int i = 5; i > 0; i++)
    {
        if (i % 2 == 0)
        {
            Particle.publish("Deakin_RIOT_SIT210_Photon_Buddy", "wave");
        }
        else
        {
            Particle.publish("Deakin_RIOT_SIT210_Photon_Buddy", "pat");
        }
        delay(10s);
    
    }

}



void myHandler(const char *event, const char *data)
{
    if(strcmp(data, "wave") == 0)
    {
        digitalWrite(led1, HIGH);
        delay(1s);
        digitalWrite(led1, LOW);
    }
    else if(strcmp(data, "pat") == 0)
    {
        digitalWrite(led1, HIGH);
        delay(3s);
        digitalWrite(led1, LOW);
    }
    else
    {
        
    }
}
