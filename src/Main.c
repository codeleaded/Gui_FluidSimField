#include "/home/codeleaded/System/Static/Library/WindowEngine1.0.h"
#include "/home/codeleaded/System/Static/Library/FluidField.h"

#define FLUID_INTERACTION_RADIUS 10.0f

//FluidField field;

void Setup(AlxWindow* w){
    //field = FluidField_New(
    //    GetWidth(w),
    //    GetHeight(w)
    //);

    init();
}
void Update(AlxWindow* w){
    if(Stroke(ALX_MOUSE_L).DOWN){
        const Vec2 dir = Vec2_Mulf(Vec2_Sub(GetMouse(),GetMouseBefore()),10.0f);
        //FluidField_Interact(&field,GetMouse().x,GetMouse().y,dir,FLUID_INTERACTION_RADIUS);
        apply_point_force(GetMouse().x,GetMouse().y,dir.x,dir.y,FLUID_INTERACTION_RADIUS);
    }

    //FluidField_Update(&field,w->ElapsedTime);
    
    Clear(BLACK);
    
    //FluidField_Render(WINDOW_STD_ARGS,&field,(Vec2){ 0.0f,0.0f });

    step();

    for(unsigned int y = 0;y<NY;y++){
		for(unsigned int x = 0;x<NX;x++){
			const float uc = u[y * NX + x];
			const float vc = v[y * NX + x];

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

			w->Buffer[y * NX + x] = c;
		}
	}
}
void Delete(AlxWindow* w){
    //FluidField_Free(&field);

    destroy();
}

int main() {
    if(Create("Fluid Sim - Flow Field",128,128,8,8,Setup,Update,Delete)){
        Start();
    }
    return 0;
}
