/**
 CScene2D
 @brief A class which manages the 2D game scene
 By: Toh Da Jun
 Date: Mar 2020
 */
#pragma once

// Include GLEW
#ifndef GLEW_STATIC
#include <GL/glew.h>
#define GLEW_STATIC
#endif

// Include GLM
#include <includes/glm.hpp>
#include <includes/gtc/matrix_transform.hpp>
#include <includes/gtc/type_ptr.hpp>

// Include Shader Manager
#include "RenderControl\ShaderManager.h"

// Include vector
#include <vector>

// Include Keyboard controller
#include "Inputs\KeyboardController.h"

// Add your include files here
// Include Singleton Template
#include "DesignPatterns\SingletonTemplate.h"

// Include the Map2D as we will use it to check the player's movements and actions
#include "Map2D.h"
// Include CPlayer2D
#include "Player2D.h"

// Include GUI_Scene2D
#include "GUI_Scene2D.h"

// Include Game Manager
#include "GameManager.h"

class CScene2D : public CSingletonTemplate<CScene2D>
{
	friend CSingletonTemplate<CScene2D>;
public:
	// Init
	bool Init(void);
	/*bool Init(const unsigned int uiNumLevels = 1,
				const unsigned int uiNumRows = 24,
				const unsigned int uiNumCols = 32);*/

	// Update
	bool Update(const double dElapsedTime);

	// PreRender
	void PreRender(void);

	// Render
	void Render(void);

	// PostRender
	void PostRender(void);

protected:
	// Keyboard Controller singleton instance
	CKeyboardController* cKeyboardController;

	// A transformation matrix for controlling where to render the entities
	glm::mat4 transform;

	// Add your variables and methods here.
	// The handler containing the instance of the 2D Map
	CMap2D* cMap2D;
	// The handler containing the instance of CPlayer2D
	CPlayer2D* cPlayer2D;

	CGUI_Scene2D* cGUI_Scene2D;
	CGameManager* cGameManager;

	// Constructor
	CScene2D(void);
	// Destructor
	virtual ~CScene2D(void);
};

