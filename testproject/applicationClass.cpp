////////////////////////////////////////////////////////////////////////////////
// Filename: applicationclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "applicationclass.h"


ApplicationClass::ApplicationClass()
{
	m_Direct3D = 0;
	m_Camera = 0;
	m_Model = 0;
	yellow_Cylinder_Model = 0;
	black_Torus_Model = 0;
	yellow_Cone_Model = 0;
	shard_Sphere_Model = 0;
	m_LightShader = 0;
	m_Light = 0;
	movement = 0.0f;
	isMove = false;
	moveForward = true;
	x_position = 0.0f;
	y_position = 5.0f;
	z_position = -15.0f;
	x_rotate = 0.0f;
	y_rotate = 0.0f;
	z_rotate = 0.0f;
	x_center = 0.0f;
	y_center = 5.0f;
	z_center = -14.0f;
	azimuth = 0.0f;
	
	universalBox = 0.0f;
	trainXPos = -6.0f;
	mainAnimation = false;
	
	doorOpen = false;
	door = 0.0f;

	goUp = false;
	blackToggle = 0.0f;

	upArm = 0.0f;
	armAnim = false;

	lowArmToggle = 0.0f;
	lowArm = 0.0f;
	lowArmExt = 0.0f;
	lowArmAnim = false;

	gloveAnim = false;
	gloveSize = 0.0f;

	counterWait = false;
	counter = 0.0f;

	eyeOpen = false;
	eyeSize = 0.0f;
	eyeToggle = 0.0f;

	afterAnim = false;
	afterDir = true;	// true = up, false = down
}


ApplicationClass::ApplicationClass(const ApplicationClass& other)
{
}


ApplicationClass::~ApplicationClass()
{
}


bool ApplicationClass::Initialize(int screenWidth, int screenHeight, HWND hwnd)
{
	char modelFilename[128];
	char textureFilename[128];
	bool result;


	// Create and initialize the Direct3D object.
	m_Direct3D = new D3DClass;

	result = m_Direct3D->Initialize(screenWidth, screenHeight, VSYNC_ENABLED, hwnd, FULL_SCREEN, SCREEN_DEPTH, SCREEN_NEAR);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize Direct3D", L"Error", MB_OK);
		return false;
	}

	// Create the camera object.
	m_Camera = new CameraClass;

	// Set the initial position of the camera.
	m_Camera->SetPosition(0.0f, 3.0f, -10.0f);
	m_Camera->SetPosition(x_position, y_position, z_position);


	// Set the file name of the model.
	strcpy_s(modelFilename, "C:/Users/matth/source/repos/testproject/testproject/sphere.txt");

	strcpy_s(textureFilename, "C:/Users/matth/source/repos/testproject/testproject/shard.tga");
	shard_Sphere_Model = new ModelClass;
	result = shard_Sphere_Model->Initialize(m_Direct3D->GetDevice(), m_Direct3D->GetDeviceContext(), modelFilename, textureFilename);


	// Set the file name of the model.
	strcpy_s(modelFilename, "C:/Users/matth/source/repos/testproject/testproject/cube.txt");

	// Set the file name of the texture file that we will be loading.
	strcpy_s(textureFilename, "C:/Users/matth/source/repos/testproject/testproject/stone01.tga");

	// Create and initialize the model object.
	m_Model = new ModelClass;
	result = m_Model->Initialize(m_Direct3D->GetDevice(), m_Direct3D->GetDeviceContext(), modelFilename, textureFilename);
	
	strcpy_s(textureFilename, "C:/Users/matth/source/repos/testproject/testproject/window1.tga");
	window_Cube_Model = new ModelClass;
	result = window_Cube_Model->Initialize(m_Direct3D->GetDevice(), m_Direct3D->GetDeviceContext(), modelFilename, textureFilename);

	strcpy_s(textureFilename, "C:/Users/matth/source/repos/testproject/testproject/window2.tga");
	window2_Cube_Model = new ModelClass;
	result = window2_Cube_Model->Initialize(m_Direct3D->GetDevice(), m_Direct3D->GetDeviceContext(), modelFilename, textureFilename);

	strcpy_s(textureFilename, "C:/Users/matth/source/repos/testproject/testproject/red.tga");
	red_Cube_Model = new ModelClass;
	result = red_Cube_Model->Initialize(m_Direct3D->GetDevice(), m_Direct3D->GetDeviceContext(), modelFilename, textureFilename);

	strcpy_s(textureFilename, "C:/Users/matth/source/repos/testproject/testproject/green.tga");
	green_Cube_Model = new ModelClass;
	result = green_Cube_Model->Initialize(m_Direct3D->GetDevice(), m_Direct3D->GetDeviceContext(), modelFilename, textureFilename);

	strcpy_s(textureFilename, "C:/Users/matth/source/repos/testproject/testproject/gray.tga");
	gray_Cube_Model = new ModelClass;
	result = gray_Cube_Model->Initialize(m_Direct3D->GetDevice(), m_Direct3D->GetDeviceContext(), modelFilename, textureFilename);

	strcpy_s(textureFilename, "C:/Users/matth/source/repos/testproject/testproject/brown.tga");
	brown_Cube_Model = new ModelClass;
	result = brown_Cube_Model->Initialize(m_Direct3D->GetDevice(), m_Direct3D->GetDeviceContext(), modelFilename, textureFilename);

	strcpy_s(textureFilename, "C:/Users/matth/source/repos/testproject/testproject/black.tga");
	black_Cube_Model = new ModelClass;
	result = black_Cube_Model->Initialize(m_Direct3D->GetDevice(), m_Direct3D->GetDeviceContext(), modelFilename, textureFilename);

	// Set the file name of the model.
	strcpy_s(modelFilename, "C:/Users/matth/source/repos/testproject/testproject/cylinder.txt");

	strcpy_s(textureFilename, "C:/Users/matth/source/repos/testproject/testproject/yellow.tga");
	yellow_Cylinder_Model = new ModelClass;
	result = yellow_Cylinder_Model->Initialize(m_Direct3D->GetDevice(), m_Direct3D->GetDeviceContext(), modelFilename, textureFilename);


	strcpy_s(textureFilename, "C:/Users/matth/source/repos/testproject/testproject/window3.tga");
	window3_Cylinder_Model = new ModelClass;
	result = window3_Cylinder_Model->Initialize(m_Direct3D->GetDevice(), m_Direct3D->GetDeviceContext(), modelFilename, textureFilename);

	// Set the file name of the model.
	strcpy_s(modelFilename, "C:/Users/matth/source/repos/testproject/testproject/torus.txt");

	strcpy_s(textureFilename, "C:/Users/matth/source/repos/testproject/testproject/black.tga");
	black_Torus_Model = new ModelClass;
	result = black_Torus_Model->Initialize(m_Direct3D->GetDevice(), m_Direct3D->GetDeviceContext(), modelFilename, textureFilename);

	// Set the file name of the model.
	strcpy_s(modelFilename, "C:/Users/matth/source/repos/testproject/testproject/cone.txt");

	strcpy_s(textureFilename, "C:/Users/matth/source/repos/testproject/testproject/yellow.tga");
	yellow_Cone_Model = new ModelClass;
	result = yellow_Cone_Model->Initialize(m_Direct3D->GetDevice(), m_Direct3D->GetDeviceContext(), modelFilename, textureFilename);


	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	// Create and initialize the light shader object.
	m_LightShader = new LightShaderClass;

	result = m_LightShader->Initialize(m_Direct3D->GetDevice(), hwnd);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the light shader object.", L"Error", MB_OK);
		return false;
	}

	// Create and initialize the light object.
	m_Light = new LightClass;

	m_Light->SetAmbientColor(0.15f, 0.15f, 0.15f, 1.0f);
	m_Light->SetDiffuseColor(1.0f, 1.0f, 1.0f, 1.0f);
	//m_Light->SetDirection(1.0f, 1.0f, 1.0f);
	m_Light->SetDirection(10.0f, -10.0f, 10.0f);
	m_Light->SetSpecularColor(1.0f, 1.0f, 1.0f, 1.0f);
	m_Light->SetSpecularPower(32.0f);

	return true;
}


void ApplicationClass::Shutdown()
{
	// Release the light object.
	if (m_Light)
	{
		delete m_Light;
		m_Light = 0;
	}

	// Release the light shader object.
	if (m_LightShader)
	{
		m_LightShader->Shutdown();
		delete m_LightShader;
		m_LightShader = 0;
	}

	// Release the model object.
	if (m_Model)
	{
		m_Model->Shutdown();
		delete m_Model;
		m_Model = 0;
	}

	// Release the camera object.
	if (m_Camera)
	{
		delete m_Camera;
		m_Camera = 0;
	}

	// Release the Direct3D object.
	if (m_Direct3D)
	{
		m_Direct3D->Shutdown();
		delete m_Direct3D;
		m_Direct3D = 0;
	}

	return;
}


bool ApplicationClass::Frame()
{
	static float rotation = 0.0f;
	bool result;

	if (isMove && mainAnimation == false) {
		if (moveForward) {
			if (movement < 3.0f) {
				movement += 0.01f;
				// Update the rotation variable each frame.
				rotation -= 0.0174532925f * 0.6f;
				if (rotation < -3.14f)
				{
					rotation += 3.14f;
				}
			}
			else {
				mainAnimation = true;
				doorOpen = true;
				blackToggle = 1.4f;
			}
		}
		else {
			if (movement > -7.0f) {
				movement -= 0.01f;
				// Update the rotation variable each frame.
				rotation += 0.0174532925f * 0.6f;
				if (rotation > 3.14f)
				{
					rotation -= 3.14f;
				}
			}
		}
	}

#pragma region mainAnimation
	if (mainAnimation) {
		if (doorOpen) {
			if (trainXPos == 0.0f) {
				if (door < 0.3f) {
					door = 0.3f;
					doorOpen = false;
					goUp = true;
				}
				else {
					door -= 0.01f;
				}
			}
			else if (door < 1.3f) {
				door += 0.01f;
			}
			else {
				door = 1.3f;
				if (movement >= 6.0f) {
					trainXPos = 0.0f;
					door -= 0.01f;
				}
				else {
					movement += 0.01f;
					rotation -= 0.0174532925f * 0.6f;
				}
			}
		}
		else if (goUp) {
			if (universalBox > 2.0f) {
				universalBox = 2.0f;
				goUp = false;
				armAnim = true;
			}
			else {
				universalBox += 0.01f;
			}
		}
		else if (armAnim) {
			if (upArm >= 1.9f) {
				upArm = 1.9f;
				armAnim = false;
				lowArmAnim = true;
				lowArmToggle = 0.15f;
			}
			else {
				upArm += 0.01f;
			}
		}
		else if (lowArmAnim) {
			if (lowArm >= 1.0f) {
				lowArm = 1.0f;
				lowArmAnim = false;
				gloveAnim = true;
			}
			else {
				lowArm += 0.005f;
				lowArmExt += 0.004f;
			}
		}
		else if (gloveAnim) {
			if (gloveSize >= 0.3f) {
				gloveAnim = 0.3f;
				gloveAnim = false;
				counterWait = true;
			}
			else {
				gloveSize += 0.001f;
			}
		}
		else if (counterWait) {
			if (counter < 10.0f) {
				counter = 0.0f;
				eyeToggle = 0.4f;
				counterWait = false;
				eyeOpen = true;
			}
			else {
				counter += 0.1f;
			}
		}
		else if (eyeOpen) {
			if (eyeSize >= 0.4f) {
				eyeSize = 0.4f;
				eyeOpen = false;
				afterAnim = true;
			}
			else {
				eyeSize += 0.005f;
			}
		}
		else if (afterAnim) {
			if (counter > 0.0f) {
				if (counter >= 5.0f) {
					counter = 0.0f;
				}
				else {
					counter += 0.1f;
				}
			}
			else if (afterDir) {
				if (universalBox >= 2.25f) {
					universalBox = 2.25f;
					afterDir = false;
					counter += 0.1f;
				}
				else {
					universalBox += 0.001f;
				}
			}
			else {
				if (universalBox <= 2.0f) {
					universalBox = 2.0f;
					afterDir = true;
					counter += 0.1f;
				}
				else {
					universalBox -= 0.001f;
				}
			}
		}
	}
#pragma endregion

	// Render the graphics scene.
	result = Render(rotation);
	if (!result)
	{
		return false;
	}

	return true;
}


void ApplicationClass::KeyCallback(char key)
{
	float pi = 2 * acos(0.0);
	//x = (eye[0] + cos(-azimuth / 45 + DEG2RAD));
	//y = (eye[1] + cos(elevation * DEG2RAD));
	//z = (eye[2] + sin(-azimuth / 45 + DEG2RAD));
	if (key == 'W') {	// Camera moves forward.
		float dir = x_center - x_position;
		x_position = x_position - dir * 0.1;
		dir = z_center - z_position;
		z_position = z_position + dir * 0.1;

		x_center = x_position + sin(-y_rotate/1.3 / 45 + (pi / 180));
		z_center = z_position + cos(-y_rotate/1.3 / 45 + (pi / 180));

		m_Camera->SetPosition(x_position, y_position, z_position);
	}
	else if (key == 'S') {	// Camera moves backwards.
		float dir = x_center - x_position;
		x_position = x_position - dir * 0.1;
		dir = z_center - z_position;
		z_position = z_position + dir * 0.1;

		x_center = x_position - sin(-y_rotate / 1.3 / 45 + (pi / 180));
		z_center = z_position - cos(-y_rotate / 1.3 / 45 + (pi / 180));

		m_Camera->SetPosition(x_position, y_position, z_position);
	}
	else if (key == 'A') {	// Camera moves left.
		//x_position -= 0.1;
		float dir = x_center - x_position;
		x_position = x_position + dir * 0.1;
		dir = z_center - z_position;
		z_position = z_position + dir * 0.1;

		x_center = x_position - cos(-y_rotate / 1.3 / 45 + (pi / 180));
		z_center = z_position - sin(-y_rotate / 1.3 / 45 + (pi / 180));

		m_Camera->SetPosition(x_position, y_position, z_position);
	}
	else if (key == 'D') {	// Camera moves right.
		//x_position += 0.1;
		float dir = x_center - x_position;
		x_position = x_position - dir * 0.1;
		dir = z_center - z_position;
		z_position = z_position - dir * 0.1;

		x_center = x_position - cos(-y_rotate / 1.3 / 45 + (pi / 180));
		z_center = z_position - sin(-y_rotate / 1.3 / 45 + (pi / 180));

		m_Camera->SetPosition(x_position, y_position, z_position);
	}

	else if (key == '_') {	// Camera moves up.
		y_position += 0.1;
		m_Camera->SetPosition(x_position, y_position, z_position);
	}
	else if (key == 'C') {	// Camera moves down.
		y_position -= 0.1;
		m_Camera->SetPosition(x_position, y_position, z_position);
	}

	else if (key == 'R') {	// Camera rotates right.
		y_rotate += 2.0;
		if (y_rotate >= 360.0) {
			y_rotate -= 360.0;
		}
		m_Camera->SetRotation(x_rotate, y_rotate, z_rotate);
	}
	else if (key == 'L') {	// Camera rotates left.
		y_rotate -= 2.0;
		if (y_rotate <= 0.0) {
			y_rotate += 360.0;
		}
		m_Camera->SetRotation(x_rotate, y_rotate, z_rotate);
	}
	else if (key == '+') {	// Camera rotates up.
		x_rotate -= 0.5;
		m_Camera->SetRotation(x_rotate, y_rotate, z_rotate);
	}
	else if (key == '-') {	// Camera rotates down.
		x_rotate += 0.5;
		m_Camera->SetRotation(x_rotate, y_rotate, z_rotate);
	}

	if (key == 'P') {  // Toggle movement.
		isMove = !isMove;
	}
	if (isMove) {
		if (key == 'O') {  // Change direction
			moveForward = !moveForward;
		}
	}
}


bool ApplicationClass::Render(float rotation)
{
	XMMATRIX worldMatrix, viewMatrix, projectionMatrix, rotateMatrix, translateMatrix, scaleMatrix, srMatrix;
	bool result;


	// Clear the buffers to begin the scene.
	m_Direct3D->BeginScene(1.0f, 1.0f, 1.0f, 1.0f);

	// Generate the view matrix based on the camera's position.
	m_Camera->Render();

	// Get the world, view, and projection matrices from the camera and d3d objects.
	m_Direct3D->GetWorldMatrix(worldMatrix);
	m_Camera->GetViewMatrix(viewMatrix);
	m_Direct3D->GetProjectionMatrix(projectionMatrix);

	//floor

	scaleMatrix = XMMatrixScaling(30.0f, 0.1f, 30.0f);  // Build the scaling matrix.
	translateMatrix = XMMatrixTranslation(10.0f, -0.1f, 0.0f);  // Build the translation matrix.

	// Multiply the scale, rotation, and translation matrices together to create the final world transformation matrix.
	worldMatrix = XMMatrixMultiply(scaleMatrix, translateMatrix);

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	m_Model->Render(m_Direct3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_Direct3D->GetDeviceContext(), m_Model->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix, m_Model->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}



	float wood = -13.5f;

	for (int i = 0; i < 24; i++) {
		scaleMatrix = XMMatrixScaling(0.1f, 0.1f, 1.0f);
		//rotateMatrix = XMMatrixRotationY(rotation);  // Build the rotation matrix.
		translateMatrix = XMMatrixTranslation(wood, 0.0f, 0.0f);  // Build the translation matrix.
		wood = wood + 0.5;

		// Multiply them together to create the final world transformation matrix.
		worldMatrix = XMMatrixMultiply(scaleMatrix, translateMatrix);

		// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
		brown_Cube_Model->Render(m_Direct3D->GetDeviceContext());

		// Render the model using the light shader.
		result = m_LightShader->Render(m_Direct3D->GetDeviceContext(), brown_Cube_Model->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix, brown_Cube_Model->GetTexture(),
			m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
			m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
		if (!result)
		{
			return false;
		}
	}

	//tracks

	scaleMatrix = XMMatrixScaling(6.0f, 0.1f, 0.1f);  // Build the scaling matrix.
	//rotateMatrix = XMMatrixRotationY(rotation);  // Build the rotation matrix.
	translateMatrix = XMMatrixTranslation(-7.75f, 0.2f, 0.75f);  // Build the translation matrix.

	// Multiply the scale, rotation, and translation matrices together to create the final world transformation matrix.
	worldMatrix = XMMatrixMultiply(scaleMatrix, translateMatrix);

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	gray_Cube_Model->Render(m_Direct3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_Direct3D->GetDeviceContext(), gray_Cube_Model->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix, gray_Cube_Model->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	scaleMatrix = XMMatrixScaling(6.0f, 0.1f, 0.1f);  // Build the scaling matrix.
	translateMatrix = XMMatrixTranslation(-7.75f, 0.2f, -0.75f);  // Build the translation matrix.

	// Multiply the scale, rotation, and translation matrices together to create the final world transformation matrix.
	worldMatrix = XMMatrixMultiply(scaleMatrix, translateMatrix);

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	gray_Cube_Model->Render(m_Direct3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_Direct3D->GetDeviceContext(), gray_Cube_Model->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix, gray_Cube_Model->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}


	//sphere

	scaleMatrix = XMMatrixScaling(10.0f, 10.0f, 10.0f);  // Build the scaling matrix.
	rotateMatrix = XMMatrixRotationY(rotation);  // Build the rotation matrix.
	translateMatrix = XMMatrixTranslation(-5.0f, 20.0f, 40.0f);  // Build the translation matrix.

	// Multiply the scale, rotation, and translation matrices together to create the final world transformation matrix.
	worldMatrix = XMMatrixMultiply(scaleMatrix, rotateMatrix);
	worldMatrix = XMMatrixMultiply(worldMatrix, translateMatrix);

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	shard_Sphere_Model->Render(m_Direct3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_Direct3D->GetDeviceContext(), shard_Sphere_Model->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix, shard_Sphere_Model->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

#pragma region Box Extra
	//bottom box black

	scaleMatrix = XMMatrixScaling(blackToggle, door, 1.3f);  // Build the scaling matrix.
	translateMatrix = XMMatrixTranslation(-0.2f, 1.4f + universalBox, 0.0f);  // Build the translation matrix.

	// Multiply the scale, rotation, and translation matrices together to create the final world transformation matrix.
	worldMatrix = XMMatrixMultiply(scaleMatrix, translateMatrix);

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	black_Cube_Model->Render(m_Direct3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_Direct3D->GetDeviceContext(), black_Cube_Model->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix, black_Cube_Model->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	#pragma region Eyes
	//L eye

	scaleMatrix = XMMatrixScaling(eyeToggle, eyeSize, 0.15f);  // Build the scaling matrix.
	rotateMatrix = XMMatrixRotationZ(1.57f);
	translateMatrix = XMMatrixTranslation(-0.15f, 5.4f + universalBox, 0.25f);  // Build the translation matrix.

	// Multiply the scale, rotation, and translation matrices together to create the final world transformation matrix.
	worldMatrix = XMMatrixMultiply(scaleMatrix, rotateMatrix);
	worldMatrix = XMMatrixMultiply(worldMatrix, translateMatrix);

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	yellow_Cylinder_Model->Render(m_Direct3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_Direct3D->GetDeviceContext(), yellow_Cylinder_Model->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix, yellow_Cylinder_Model->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	//R eye

	scaleMatrix = XMMatrixScaling(eyeToggle, eyeSize, 0.15f);  // Build the scaling matrix.
	rotateMatrix = XMMatrixRotationZ(1.57f);
	translateMatrix = XMMatrixTranslation(-0.15f, 5.4f + universalBox, -0.25f);  // Build the translation matrix.

	// Multiply the scale, rotation, and translation matrices together to create the final world transformation matrix.
	worldMatrix = XMMatrixMultiply(scaleMatrix, rotateMatrix);
	worldMatrix = XMMatrixMultiply(worldMatrix, translateMatrix);

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	yellow_Cylinder_Model->Render(m_Direct3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_Direct3D->GetDeviceContext(), yellow_Cylinder_Model->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix, yellow_Cylinder_Model->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}
	#pragma endregion

	#pragma region Arms
	
	#pragma region L Arm
	//upper arm

	scaleMatrix = XMMatrixScaling(0.25f, 0.25f, 1.3f);  // Build the scaling matrix.
	translateMatrix = XMMatrixTranslation(0.0f, 1.4f + universalBox, -upArm);  // Build the translation matrix.

	// Multiply the scale, rotation, and translation matrices together to create the final world transformation matrix.
	worldMatrix = XMMatrixMultiply(scaleMatrix, translateMatrix);

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	green_Cube_Model->Render(m_Direct3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_Direct3D->GetDeviceContext(), green_Cube_Model->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix, green_Cube_Model->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	//lower arm
				//-0.8f
	scaleMatrix = XMMatrixScaling(lowArm, lowArmToggle, lowArmToggle);  // Build the scaling matrix.
	translateMatrix = XMMatrixTranslation(-lowArmExt, 1.4f + universalBox, -3.0f);  // Build the translation matrix.

	// Multiply the scale, rotation, and translation matrices together to create the final world transformation matrix.
	worldMatrix = XMMatrixMultiply(scaleMatrix, translateMatrix);

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	brown_Cube_Model->Render(m_Direct3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_Direct3D->GetDeviceContext(), brown_Cube_Model->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix, brown_Cube_Model->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	//glove

	scaleMatrix = XMMatrixScaling(gloveSize, gloveSize, gloveSize);  // Build the scaling matrix.
	translateMatrix = XMMatrixTranslation(-1.7f, 1.4f + universalBox, -3.0f);  // Build the translation matrix.

	// Multiply the scale, rotation, and translation matrices together to create the final world transformation matrix.
	worldMatrix = XMMatrixMultiply(scaleMatrix, translateMatrix);

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	red_Cube_Model->Render(m_Direct3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_Direct3D->GetDeviceContext(), red_Cube_Model->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix, red_Cube_Model->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}
	#pragma endregion

	#pragma region R Arm
	//upper arm

	scaleMatrix = XMMatrixScaling(0.25f, 0.25f, 1.3f);  // Build the scaling matrix.
	translateMatrix = XMMatrixTranslation(0.0f, 1.4f + universalBox, upArm);  // Build the translation matrix.

	// Multiply the scale, rotation, and translation matrices together to create the final world transformation matrix.
	worldMatrix = XMMatrixMultiply(scaleMatrix, translateMatrix);

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	green_Cube_Model->Render(m_Direct3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_Direct3D->GetDeviceContext(), green_Cube_Model->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix, green_Cube_Model->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	//lower arm

	scaleMatrix = XMMatrixScaling(lowArm, lowArmToggle, lowArmToggle);  // Build the scaling matrix.
	translateMatrix = XMMatrixTranslation(-lowArmExt, 1.4f + universalBox, 3.0f);  // Build the translation matrix.

	// Multiply the scale, rotation, and translation matrices together to create the final world transformation matrix.
	worldMatrix = XMMatrixMultiply(scaleMatrix, translateMatrix);

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	brown_Cube_Model->Render(m_Direct3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_Direct3D->GetDeviceContext(), brown_Cube_Model->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix, brown_Cube_Model->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	//glove

	scaleMatrix = XMMatrixScaling(gloveSize, gloveSize, gloveSize);  // Build the scaling matrix.
	translateMatrix = XMMatrixTranslation(-1.7f, 1.4f + universalBox, 3.0f);  // Build the translation matrix.

	// Multiply the scale, rotation, and translation matrices together to create the final world transformation matrix.
	worldMatrix = XMMatrixMultiply(scaleMatrix, translateMatrix);

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	red_Cube_Model->Render(m_Direct3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_Direct3D->GetDeviceContext(), red_Cube_Model->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix, red_Cube_Model->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}
	#pragma endregion

	#pragma endregion
	
	#pragma region Legs
	//L Leg
	scaleMatrix = XMMatrixScaling(0.3f, 1.4f, 0.3f);  // Build the scaling matrix.
	translateMatrix = XMMatrixTranslation(-0.2f, 1.4f, -0.75f);  // Build the translation matrix.

	// Multiply the scale, rotation, and translation matrices together to create the final world transformation matrix.
	worldMatrix = XMMatrixMultiply(scaleMatrix, translateMatrix);

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	gray_Cube_Model->Render(m_Direct3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_Direct3D->GetDeviceContext(), gray_Cube_Model->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix, gray_Cube_Model->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	//L Shoe
	scaleMatrix = XMMatrixScaling(0.7f, 0.4f, 0.5f);  // Build the scaling matrix.
	translateMatrix = XMMatrixTranslation(-0.3f, 0.25f, -0.75f);  // Build the translation matrix.

	// Multiply the scale, rotation, and translation matrices together to create the final world transformation matrix.
	worldMatrix = XMMatrixMultiply(scaleMatrix, translateMatrix);

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	red_Cube_Model->Render(m_Direct3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_Direct3D->GetDeviceContext(), red_Cube_Model->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix, red_Cube_Model->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}


	//R Leg
	scaleMatrix = XMMatrixScaling(0.3f, 1.4f, 0.3f);  // Build the scaling matrix.
	translateMatrix = XMMatrixTranslation(-0.2f, 1.4f, 0.75f);  // Build the translation matrix.

	// Multiply the scale, rotation, and translation matrices together to create the final world transformation matrix.
	worldMatrix = XMMatrixMultiply(scaleMatrix, translateMatrix);

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	gray_Cube_Model->Render(m_Direct3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_Direct3D->GetDeviceContext(), gray_Cube_Model->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix, gray_Cube_Model->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	//R Shoe
	scaleMatrix = XMMatrixScaling(0.7f, 0.4f, 0.5f);  // Build the scaling matrix.
	translateMatrix = XMMatrixTranslation(-0.3f, 0.25f, 0.75f);  // Build the translation matrix.

	// Multiply the scale, rotation, and translation matrices together to create the final world transformation matrix.
	worldMatrix = XMMatrixMultiply(scaleMatrix, translateMatrix);

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	red_Cube_Model->Render(m_Direct3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_Direct3D->GetDeviceContext(), red_Cube_Model->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix, red_Cube_Model->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}
	#pragma endregion

#pragma endregion

#pragma region Box
//bottom box

	scaleMatrix = XMMatrixScaling(1.5f, 1.5f, 1.5f);  // Build the scaling matrix.
	translateMatrix = XMMatrixTranslation(0.0f, 1.4f + universalBox, 0.0f);  // Build the translation matrix.

	// Multiply the scale, rotation, and translation matrices together to create the final world transformation matrix.
	worldMatrix = XMMatrixMultiply(scaleMatrix, translateMatrix);

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	m_Model->Render(m_Direct3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_Direct3D->GetDeviceContext(), m_Model->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix, m_Model->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	//middle box

	scaleMatrix = XMMatrixScaling(1.0f, 1.0f, 1.0f);  // Build the scaling matrix.
	translateMatrix = XMMatrixTranslation(0.0f, 3.9f + universalBox, 0.0f);  // Build the translation matrix.

	// Multiply the scale, rotation, and translation matrices together to create the final world transformation matrix.
	worldMatrix = XMMatrixMultiply(scaleMatrix, translateMatrix);

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	m_Model->Render(m_Direct3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_Direct3D->GetDeviceContext(), m_Model->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix, m_Model->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	//top box

	scaleMatrix = XMMatrixScaling(0.5f, 0.5f, 0.5f);  // Build the scaling matrix.
	translateMatrix = XMMatrixTranslation(0.0f, 5.4f + universalBox, 0.0f);  // Build the translation matrix.

	// Multiply the scale, rotation, and translation matrices together to create the final world transformation matrix.
	worldMatrix = XMMatrixMultiply(scaleMatrix, translateMatrix);

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	m_Model->Render(m_Direct3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_Direct3D->GetDeviceContext(), m_Model->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix, m_Model->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}
#pragma endregion
	
	

	//train

#pragma region Train Body
	//body
	scaleMatrix = XMMatrixScaling(1.0f, 0.5f, 0.5f);  // Build the scaling matrix.
	translateMatrix = XMMatrixTranslation(( -6.0f + movement), 1.0f + universalBox, 0.0f);  // Build the translation matrix.

	// Multiply the scale, rotation, and translation matrices together to create the final world transformation matrix.
	worldMatrix = XMMatrixMultiply(scaleMatrix, translateMatrix);

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	red_Cube_Model->Render(m_Direct3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_Direct3D->GetDeviceContext(), red_Cube_Model->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix, red_Cube_Model->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	//back
	scaleMatrix = XMMatrixScaling(0.45f, 0.25f, 0.5f);  // Build the scaling matrix.
	translateMatrix = XMMatrixTranslation((-6.55f + movement), 1.75f + universalBox, 0.0f);  // Build the translation matrix.

	// Multiply the scale, rotation, and translation matrices together to create the final world transformation matrix.
	worldMatrix = XMMatrixMultiply(scaleMatrix, translateMatrix);

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	green_Cube_Model->Render(m_Direct3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_Direct3D->GetDeviceContext(), green_Cube_Model->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix, green_Cube_Model->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	//cylinder
	scaleMatrix = XMMatrixScaling(0.125f, 0.15f, 0.125f);  // Build the scaling matrix.
	translateMatrix = XMMatrixTranslation((-5.45f + movement), 1.60f + universalBox, 0.0f);  // Build the translation matrix.

	// Multiply the scale, rotation, and translation matrices together to create the final world transformation matrix.
	worldMatrix = XMMatrixMultiply(scaleMatrix, translateMatrix);

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	yellow_Cylinder_Model->Render(m_Direct3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_Direct3D->GetDeviceContext(), yellow_Cylinder_Model->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix, yellow_Cylinder_Model->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	//cone
	scaleMatrix = XMMatrixScaling(0.25f, 0.25f, 0.25f);  // Build the scaling matrix.
	rotateMatrix = XMMatrixRotationX(3.14f);  // Build the rotation matrix.
	translateMatrix = XMMatrixTranslation((-5.45f + movement), 1.75f + universalBox, 0.0f);  // Build the translation matrix.

	// Multiply the scale, rotation, and translation matrices together to create the final world transformation matrix.
	worldMatrix = XMMatrixMultiply(scaleMatrix, rotateMatrix);
	worldMatrix = XMMatrixMultiply(worldMatrix, translateMatrix);

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	yellow_Cone_Model->Render(m_Direct3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_Direct3D->GetDeviceContext(), yellow_Cone_Model->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix, yellow_Cone_Model->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}
#pragma endregion

#pragma region Wheels

	#pragma region Torus Wheels
	scaleMatrix = XMMatrixScaling(0.3f, 0.5f, 0.3f);  // Build the scaling matrix.
	rotateMatrix = XMMatrixRotationX(1.57f);  // Build the rotation matrix.
	translateMatrix = XMMatrixTranslation((-5.45f + movement), 0.65f + universalBox, -0.6f);  // Build the translation matrix.

	// Multiply the scale, rotation, and translation matrices together to create the final world transformation matrix.
	worldMatrix = XMMatrixMultiply(scaleMatrix, rotateMatrix);
	worldMatrix = XMMatrixMultiply(worldMatrix, translateMatrix);

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	black_Torus_Model->Render(m_Direct3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_Direct3D->GetDeviceContext(), black_Torus_Model->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix, black_Torus_Model->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	scaleMatrix = XMMatrixScaling(0.3f, 0.5f, 0.3f);  // Build the scaling matrix.
	rotateMatrix = XMMatrixRotationX(1.57f);  // Build the rotation matrix.
	translateMatrix = XMMatrixTranslation((-5.45f + movement), 0.65f + universalBox, 0.6f);  // Build the translation matrix.

	// Multiply the scale, rotation, and translation matrices together to create the final world transformation matrix.
	worldMatrix = XMMatrixMultiply(scaleMatrix, rotateMatrix);
	worldMatrix = XMMatrixMultiply(worldMatrix, translateMatrix);

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	black_Torus_Model->Render(m_Direct3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_Direct3D->GetDeviceContext(), black_Torus_Model->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix, black_Torus_Model->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	scaleMatrix = XMMatrixScaling(0.3f, 0.5f, 0.3f);  // Build the scaling matrix.
	rotateMatrix = XMMatrixRotationX(1.57f);  // Build the rotation matrix.
	translateMatrix = XMMatrixTranslation((-6.55f + movement), 0.65f + universalBox, -0.6f);  // Build the translation matrix.

	// Multiply the scale, rotation, and translation matrices together to create the final world transformation matrix.
	worldMatrix = XMMatrixMultiply(scaleMatrix, rotateMatrix);
	worldMatrix = XMMatrixMultiply(worldMatrix, translateMatrix);

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	black_Torus_Model->Render(m_Direct3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_Direct3D->GetDeviceContext(), black_Torus_Model->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix, black_Torus_Model->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	scaleMatrix = XMMatrixScaling(0.3f, 0.5f, 0.3f);  // Build the scaling matrix.
	rotateMatrix = XMMatrixRotationX(1.57f);  // Build the rotation matrix.
	translateMatrix = XMMatrixTranslation((-6.55f + movement), 0.65f + universalBox, 0.6f);  // Build the translation matrix.

	// Multiply the scale, rotation, and translation matrices together to create the final world transformation matrix.
	worldMatrix = XMMatrixMultiply(scaleMatrix, rotateMatrix);
	worldMatrix = XMMatrixMultiply(worldMatrix, translateMatrix);

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	black_Torus_Model->Render(m_Direct3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_Direct3D->GetDeviceContext(), black_Torus_Model->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix, black_Torus_Model->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}
	#pragma endregion

	#pragma region Front Right Wheel
	// Front Right
	scaleMatrix = XMMatrixScaling(0.05f, 0.25f, 0.05f);  // Build the scaling matrix.
	rotateMatrix = XMMatrixRotationZ(0.0f + rotation);  // Build the rotation matrix.
	translateMatrix = XMMatrixTranslation((-5.45f + movement), 0.65f + universalBox, -0.6f);  // Build the translation matrix.

	// Multiply the scale, rotation, and translation matrices together to create the final world transformation matrix.
	worldMatrix = XMMatrixMultiply(scaleMatrix, rotateMatrix);
	worldMatrix = XMMatrixMultiply(worldMatrix, translateMatrix);

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	black_Cube_Model->Render(m_Direct3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_Direct3D->GetDeviceContext(), black_Cube_Model->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix, black_Cube_Model->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	scaleMatrix = XMMatrixScaling(0.05f, 0.25f, 0.05f);  // Build the scaling matrix.
	rotateMatrix = XMMatrixRotationZ(1.046f + rotation);  // Build the rotation matrix.
	translateMatrix = XMMatrixTranslation((-5.45f + movement), 0.65f + universalBox, -0.6f);  // Build the translation matrix.

	// Multiply the scale, rotation, and translation matrices together to create the final world transformation matrix.
	worldMatrix = XMMatrixMultiply(scaleMatrix, rotateMatrix);
	worldMatrix = XMMatrixMultiply(worldMatrix, translateMatrix);

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	black_Cube_Model->Render(m_Direct3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_Direct3D->GetDeviceContext(), black_Cube_Model->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix, black_Cube_Model->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	scaleMatrix = XMMatrixScaling(0.05f, 0.25f, 0.05f);  // Build the scaling matrix.
	rotateMatrix = XMMatrixRotationZ(-1.046f + rotation);  // Build the rotation matrix.
	translateMatrix = XMMatrixTranslation((-5.45f + movement), 0.65f + universalBox, -0.6f);  // Build the translation matrix.

	// Multiply the scale, rotation, and translation matrices together to create the final world transformation matrix.
	worldMatrix = XMMatrixMultiply(scaleMatrix, rotateMatrix);
	worldMatrix = XMMatrixMultiply(worldMatrix, translateMatrix);

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	black_Cube_Model->Render(m_Direct3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_Direct3D->GetDeviceContext(), black_Cube_Model->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix, black_Cube_Model->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}
	#pragma endregion

	#pragma region Front Left Wheel
	// Front Right
	scaleMatrix = XMMatrixScaling(0.05f, 0.25f, 0.05f);  // Build the scaling matrix.
	rotateMatrix = XMMatrixRotationZ(0.0f + rotation);  // Build the rotation matrix.
	translateMatrix = XMMatrixTranslation((-5.45f + movement), 0.65f + universalBox, 0.6f);  // Build the translation matrix.

	// Multiply the scale, rotation, and translation matrices together to create the final world transformation matrix.
	worldMatrix = XMMatrixMultiply(scaleMatrix, rotateMatrix);
	worldMatrix = XMMatrixMultiply(worldMatrix, translateMatrix);

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	black_Cube_Model->Render(m_Direct3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_Direct3D->GetDeviceContext(), black_Cube_Model->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix, black_Cube_Model->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	scaleMatrix = XMMatrixScaling(0.05f, 0.25f, 0.05f);  // Build the scaling matrix.
	rotateMatrix = XMMatrixRotationZ(1.046f + rotation);  // Build the rotation matrix.
	translateMatrix = XMMatrixTranslation((-5.45f + movement), 0.65f + universalBox, 0.6f);  // Build the translation matrix.

	// Multiply the scale, rotation, and translation matrices together to create the final world transformation matrix.
	worldMatrix = XMMatrixMultiply(scaleMatrix, rotateMatrix);
	worldMatrix = XMMatrixMultiply(worldMatrix, translateMatrix);

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	black_Cube_Model->Render(m_Direct3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_Direct3D->GetDeviceContext(), black_Cube_Model->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix, black_Cube_Model->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	scaleMatrix = XMMatrixScaling(0.05f, 0.25f, 0.05f);  // Build the scaling matrix.
	rotateMatrix = XMMatrixRotationZ(-1.046f + rotation);  // Build the rotation matrix.
	translateMatrix = XMMatrixTranslation((-5.45f + movement), 0.65f + universalBox, 0.6f);  // Build the translation matrix.

	// Multiply the scale, rotation, and translation matrices together to create the final world transformation matrix.
	worldMatrix = XMMatrixMultiply(scaleMatrix, rotateMatrix);
	worldMatrix = XMMatrixMultiply(worldMatrix, translateMatrix);

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	black_Cube_Model->Render(m_Direct3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_Direct3D->GetDeviceContext(), black_Cube_Model->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix, black_Cube_Model->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}
	#pragma endregion

	#pragma region Back Right Wheel
	// Front Right
	scaleMatrix = XMMatrixScaling(0.05f, 0.25f, 0.05f);  // Build the scaling matrix.
	rotateMatrix = XMMatrixRotationZ(0.0f + rotation);  // Build the rotation matrix.
	translateMatrix = XMMatrixTranslation((-6.55f + movement), 0.65f + universalBox, -0.6f);  // Build the translation matrix.

	// Multiply the scale, rotation, and translation matrices together to create the final world transformation matrix.
	worldMatrix = XMMatrixMultiply(scaleMatrix, rotateMatrix);
	worldMatrix = XMMatrixMultiply(worldMatrix, translateMatrix);

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	black_Cube_Model->Render(m_Direct3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_Direct3D->GetDeviceContext(), black_Cube_Model->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix, black_Cube_Model->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	scaleMatrix = XMMatrixScaling(0.05f, 0.25f, 0.05f);  // Build the scaling matrix.
	rotateMatrix = XMMatrixRotationZ(1.046f + rotation);  // Build the rotation matrix.
	translateMatrix = XMMatrixTranslation((-6.55f + movement), 0.65f + universalBox, -0.6f);  // Build the translation matrix.

	// Multiply the scale, rotation, and translation matrices together to create the final world transformation matrix.
	worldMatrix = XMMatrixMultiply(scaleMatrix, rotateMatrix);
	worldMatrix = XMMatrixMultiply(worldMatrix, translateMatrix);

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	black_Cube_Model->Render(m_Direct3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_Direct3D->GetDeviceContext(), black_Cube_Model->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix, black_Cube_Model->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	scaleMatrix = XMMatrixScaling(0.05f, 0.25f, 0.05f);  // Build the scaling matrix.
	rotateMatrix = XMMatrixRotationZ(-1.046f + rotation);  // Build the rotation matrix.
	translateMatrix = XMMatrixTranslation((-6.55f + movement), 0.65f + universalBox, -0.6f);  // Build the translation matrix.

	// Multiply the scale, rotation, and translation matrices together to create the final world transformation matrix.
	worldMatrix = XMMatrixMultiply(scaleMatrix, rotateMatrix);
	worldMatrix = XMMatrixMultiply(worldMatrix, translateMatrix);

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	black_Cube_Model->Render(m_Direct3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_Direct3D->GetDeviceContext(), black_Cube_Model->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix, black_Cube_Model->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}
	#pragma endregion

	#pragma region Back Right Wheel
	// Front Right
	scaleMatrix = XMMatrixScaling(0.05f, 0.25f, 0.05f);  // Build the scaling matrix.
	rotateMatrix = XMMatrixRotationZ(0.0f + rotation);  // Build the rotation matrix.
	translateMatrix = XMMatrixTranslation((-6.55f + movement), 0.65f + universalBox, 0.6f);  // Build the translation matrix.

	// Multiply the scale, rotation, and translation matrices together to create the final world transformation matrix.
	worldMatrix = XMMatrixMultiply(scaleMatrix, rotateMatrix);
	worldMatrix = XMMatrixMultiply(worldMatrix, translateMatrix);

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	black_Cube_Model->Render(m_Direct3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_Direct3D->GetDeviceContext(), black_Cube_Model->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix, black_Cube_Model->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	scaleMatrix = XMMatrixScaling(0.05f, 0.25f, 0.05f);  // Build the scaling matrix.
	rotateMatrix = XMMatrixRotationZ(1.046f + rotation);  // Build the rotation matrix.
	translateMatrix = XMMatrixTranslation((-6.55f + movement), 0.65f + universalBox, 0.6f);  // Build the translation matrix.

	// Multiply the scale, rotation, and translation matrices together to create the final world transformation matrix.
	worldMatrix = XMMatrixMultiply(scaleMatrix, rotateMatrix);
	worldMatrix = XMMatrixMultiply(worldMatrix, translateMatrix);

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	black_Cube_Model->Render(m_Direct3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_Direct3D->GetDeviceContext(), black_Cube_Model->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix, black_Cube_Model->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	scaleMatrix = XMMatrixScaling(0.05f, 0.25f, 0.05f);  // Build the scaling matrix.
	rotateMatrix = XMMatrixRotationZ(-1.046f + rotation);  // Build the rotation matrix.
	translateMatrix = XMMatrixTranslation((-6.55f + movement), 0.65f + universalBox, 0.6f);  // Build the translation matrix.

	// Multiply the scale, rotation, and translation matrices together to create the final world transformation matrix.
	worldMatrix = XMMatrixMultiply(scaleMatrix, rotateMatrix);
	worldMatrix = XMMatrixMultiply(worldMatrix, translateMatrix);

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	black_Cube_Model->Render(m_Direct3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_Direct3D->GetDeviceContext(), black_Cube_Model->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix, black_Cube_Model->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}
	#pragma endregion
	
#pragma endregion


#pragma region Buildings

	scaleMatrix = XMMatrixScaling(5.0f, 10.0f, 5.0f);  // Build the scaling matrix.
	translateMatrix = XMMatrixTranslation(-15.0f, 10.0f, 20.0f);  // Build the translation matrix.

	// Multiply the scale, rotation, and translation matrices together to create the final world transformation matrix.
	worldMatrix = XMMatrixMultiply(scaleMatrix, translateMatrix);

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	window_Cube_Model->Render(m_Direct3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_Direct3D->GetDeviceContext(), window_Cube_Model->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix, window_Cube_Model->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	scaleMatrix = XMMatrixScaling(10.0f, 7.5f, 5.0f);  // Build the scaling matrix.
	translateMatrix = XMMatrixTranslation(0.0f, 7.5f, 20.0f);  // Build the translation matrix.

	// Multiply the scale, rotation, and translation matrices together to create the final world transformation matrix.
	worldMatrix = XMMatrixMultiply(scaleMatrix, translateMatrix);

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	window2_Cube_Model->Render(m_Direct3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_Direct3D->GetDeviceContext(), window2_Cube_Model->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix, window2_Cube_Model->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	scaleMatrix = XMMatrixScaling(6.0f, 10.0f, 6.0f);  // Build the scaling matrix.
	rotateMatrix = XMMatrixRotationY(179.0f);  // Build the rotation matrix.
	translateMatrix = XMMatrixTranslation(12.5f, 10.0f, 20.0f);  // Build the translation matrix.

	// Multiply the scale, rotation, and translation matrices together to create the final world transformation matrix.
	worldMatrix = XMMatrixMultiply(scaleMatrix, rotateMatrix);
	worldMatrix = XMMatrixMultiply(worldMatrix, translateMatrix);

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	window3_Cylinder_Model->Render(m_Direct3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_Direct3D->GetDeviceContext(), window3_Cylinder_Model->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix, window3_Cylinder_Model->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

	scaleMatrix = XMMatrixScaling(10.0f, 7.5f, 5.0f);  // Build the scaling matrix.
	translateMatrix = XMMatrixTranslation(25.0f, 7.5f, 20.0f);  // Build the translation matrix.

	// Multiply the scale, rotation, and translation matrices together to create the final world transformation matrix.
	worldMatrix = XMMatrixMultiply(scaleMatrix, translateMatrix);

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	window_Cube_Model->Render(m_Direct3D->GetDeviceContext());

	// Render the model using the light shader.
	result = m_LightShader->Render(m_Direct3D->GetDeviceContext(), window_Cube_Model->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix, window_Cube_Model->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	if (!result)
	{
		return false;
	}

#pragma endregion

	// Present the rendered scene to the screen.
	m_Direct3D->EndScene();

	return true;
}