#pragma once
#include "Sprite2D.h"
class AnimationSprite : public Sprite2D
{
protected:
	GLfloat m_numFrames = 0;
	GLfloat m_currentFrame = 0;
	GLfloat m_frameTime = 0.0f;
	GLfloat m_currentTime = 0;
public:
	AnimationSprite();
	AnimationSprite(GLfloat m_numFrames, GLfloat m_frameTime, std::shared_ptr<Models> model, std::shared_ptr<Shaders> shader,
		std::shared_ptr<Texture> texture);
	void Init() override;
	void Draw() override;
	void Update(GLfloat deltatime) override;
};

