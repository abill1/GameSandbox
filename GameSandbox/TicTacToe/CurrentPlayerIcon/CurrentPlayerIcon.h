
#ifndef GAMESANDBOX_TIC_TAC_TOE_CURRENTPLAYERICON_H
#define GAMESANDBOX_TIC_TAC_TOE_CURRENTPLAYERICON_H

#include "../../Engine/Core/GameObject/GameObject.h"
#include "../Engine/Core/AssetManager/AssetDef/AssetDef.h"

namespace ABFramework
{
	class Texture;
	class Sprite;

	class CurrentPlayerIcon
	{
	public:
		enum class Player : int
		{
			ONE,
			TWO
		};

	public:
		// ----- Constructor / Destructor ----- //
		
		CurrentPlayerIcon();
		~CurrentPlayerIcon();

		// ----- Operators ----- //

		// ------ Utility ----- //
		
		void Update();
		void Draw(const Matrix& _viewProj);

		// ----- Setters ----- //

		void SetPosition(Player _player, const Point3D& _position);
		void SetScale(Player _player, const Scale& _scale);
		void SwapPlayer(Player _player);

		// ----- Getters ----- //


	private:
		const AssetDef PlayerOneText = { "..\\GameSandbox\\Assets\\Textures\\Player1X.tga","PlayerOneText", true };
		const AssetDef PlayerTwoText = { "..\\GameSandbox\\Assets\\Textures\\Player2O.tga","PlayerTwoText", true };
		Sprite* pPlayerOneIcon;
		Sprite* pPlayerTwoIcon;
		Sprite* pCurrentPlayer;

	};
}

#endif // !GAMESANDBOX_TIC_TAC_TOE_CURRENTPLAYERICON_H


