/*!
 *@brief	�Q�[���J����
 */

#pragma once

#include "tkEngine/camera/tkSpringCamera.h"
#include "tkEngine/camera/tkCameraCollisionSolver.h"

class Player;
class Car;
/*!
 *@brief	�Q�[���J�����B
 */
class GameCamera : public IGameObject{
public:
	GameCamera();
	~GameCamera();
	bool Start() override ;
	void Update() override ;
	void Render( CRenderContext& renderContext ) override;
	void SetPlayer(Player* player)
	{
		this->player = player;
	}
	void SetCar(Car* car)
	{
		this->car = car;
	}
	const CCamera& GetCamera() const
	{
		return *springCamera.GetCamera();
	}
	void SetDampingRate(float rate)
	{
		springCamera.SetDampingRate(rate);
	}
	void SetViewAngle(float angle)
	{
		m_targetViewAngle = angle;
	}
private:
	CSpringCamera springCamera;
	Car* car;
	Player*	player;
	CVector3	toPosition;		//�����_���王�_�ւ̃x�N�g���B
	float m_targetViewAngle;	//�r���[�A���O���B
	CCameraCollisionSolver cameraCollisionSolver;
};


extern GameCamera*			g_camera;				//�J�����B