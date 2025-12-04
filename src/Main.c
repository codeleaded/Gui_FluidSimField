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
        FluidField_ApplyPointForce(&field,GetMouse().x,GetMouse().y,dir.x,dir.y,FLUID_INTERACTION_RADIUS);
    }

    //FluidField_Update(&field,w->ElapsedTime);
    
    Clear(BLACK);
    
    //FluidField_Render(WINDOW_STD_ARGS,&field,(Vec2){ 0.0f,0.0f });

    FluidField_Step(&field);

    for(unsigned int y = 0;y<FLUIDFIELD_NY;y++){
		for(unsigned int x = 0;x<FLUIDFIELD_NX;x++){
			const float uc = field.u[y * FLUIDFIELD_NX + x];
			const float vc = field.v[y * FLUIDFIELD_NX + x];

			// const Pixel c = Pixel_toRGBA(
			// 	F32_Clamp(fabsf(uc),0.0f,1.0f),
			// 	F32_Clamp(fabsf(vc),0.0f,1.0f),
			// 	0.0f,
			// 	1.0f
			// );

			const float speed = sqrt(uc * uc + vc * vc);
			const Pixel c = Pixel_toRGBA(
				F32_Clamp(speed,0.0f,1.0f),
				F32_Clamp(speed,0.0f,1.0f),
				F32_Clamp(speed,0.0f,1.0f),
				1.0f
			);

			w->Buffer[y * FLUIDFIELD_NX + x] = c;
		}
	}
}
void Delete(AlxWindow* w){
    FluidField_Free(&field);
}

int main() {
    if(Create("Fluid Sim - Flow Field",128,128,8,8,Setup,Update,Delete)){
        Start();
    }
    return 0;
}
