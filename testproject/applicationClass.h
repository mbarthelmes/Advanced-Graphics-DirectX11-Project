////////////////////////////////////////////////////////////////////////////////
// Filename: applicationclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _APPLICATIONCLASS_H_
#define _APPLICATIONCLASS_H_


///////////////////////
// MY CLASS INCLUDES //
///////////////////////
#include "d3dclass.h"
#include "cameraclass.h"
#include "modelclass.h"
#include "lightshaderclass.h"
#include "lightclass.h"


/////////////
// GLOBALS //
/////////////
const bool FULL_SCREEN = true;
const bool VSYNC_ENABLED = true;
const float SCREEN_DEPTH = 1000.0f;
const float SCREEN_NEAR = 0.3f;


////////////////////////////////////////////////////////////////////////////////
// Class name: ApplicationClass
////////////////////////////////////////////////////////////////////////////////
class ApplicationClass
{
public:
	ApplicationClass();
	ApplicationClass(const ApplicationClass&);
	~ApplicationClass();

	bool Initialize(int, int, HWND);
	void Shutdown();
	bool Frame();
	void KeyCallback(char);

private:
	bool Render(float);

private:
	D3DClass* m_Direct3D;
	CameraClass* m_Camera;
	ModelClass* m_Model;
	ModelClass* yellow_Cylinder_Model;
	ModelClass* black_Torus_Model;
	ModelClass* yellow_Cone_Model;
	ModelClass* red_Cube_Model;
	ModelClass* green_Cube_Model;
	ModelClass* gray_Cube_Model;
	ModelClass* brown_Cube_Model;
	ModelClass* black_Cube_Model;
	ModelClass* shard_Sphere_Model;
	ModelClass* window_Cube_Model;
	ModelClass* window2_Cube_Model;
	ModelClass* window3_Cylinder_Model;
	LightShaderClass* m_LightShader;
	LightClass* m_Light;
	float movement;
	bool isMove;
	bool moveForward;
	float x_position;
	float y_position;
	float z_position;
	float x_rotate;
	float y_rotate;
	float z_rotate;
	float x_center;
	float y_center;
	float z_center;

	float azimuth;

	float universalBox;
	float trainXPos;
	
	bool mainAnimation;

	float blackToggle;
	
	bool doorOpen;
	float door;

	bool goUp;

	float upArm;
	bool armAnim;

	float lowArmToggle;
	float lowArm;
	float lowArmExt;
	bool lowArmAnim;

	bool gloveAnim;
	float gloveSize;

	bool counterWait;
	float counter;

	bool eyeOpen;
	float eyeSize;
	float eyeToggle;

	bool afterAnim;
	bool afterDir;
	/*ModelClass* red_Model;
	ModelClass* green_Model;
	ModelClass* yellow_Model;
	ModelClass* blue_Model;
	ModelClass* pink_Model;
	ModelClass* brown_Model;
	ModelClass* gray_Model;*/
};

#endif