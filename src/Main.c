#include "/home/codeleaded/System/Static/Library/WindowEngine1.0.h"
#include "/home/codeleaded/System/Static/Library/FluidField.h"

#define FLUID_INTERACTION_RADIUS 10.0f

FluidField field;

void Setup(AlxWindow* w){
    field = FluidField_New(
        GetWidth(w),
        GetHeight(w)
    );
}
void Update(AlxWindow* w){
    if(Stroke(ALX_MOUSE_L).DOWN){
        const Vec2 dir = Vec2_Mulf(Vec2_Sub(GetMouse(),GetMouseBefore()),10.0f);
        FluidField_Interact(&field,GetMouse().x,GetMouse().y,dir,FLUID_INTERACTION_RADIUS);
    }

    FluidField_Update(&field,w->ElapsedTime);
    
    Clear(BLACK);
    
    FluidField_Render(WINDOW_STD_ARGS,&field,(Vec2){ 0.0f,0.0f });
}
void Delete(AlxWindow* w){
    FluidField_Free(&field);
}

int main() {
    if(Create("Fluid Sim - Flow Field",125,75,16,16,Setup,Update,Delete)){
        Start();
    }
    return 0;
}
