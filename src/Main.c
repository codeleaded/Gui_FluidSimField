#include "/home/codeleaded/System/Static/Library/WindowEngine1.0.h"

void Setup(AlxWindow* w){
    Clear(BLACK);
}
void Update(AlxWindow* w){
    if(Stroke(ALX_MOUSE_L).DOWN){
        
    }
    
    Clear(BLACK);
    RenderCStr("Hello World",10,10,BLUE);
}
void Delete(AlxWindow* w){
    
}

int main() {
    if(Create("Fluid Sim - Flow Field",1000,1000,1,1,Setup,Update,Delete)){
        Start();
    }
    return 0;
}
