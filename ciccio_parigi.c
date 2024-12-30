#include "raylib.h"

#define MAIN_TITLE_ARR_LEN 8
#define CICCIO_DIALOGUES_SCREEN_INTRO_ARR_LEN 7
#define MAP_LOCATIONS_ROWS 12
#define MAP_LOCATIONS_COLS 7

typedef struct MatrixPos {
	int row;
	int col;
} MatrixPos;


bool canMoveRight(Texture* gameScenes[MAP_LOCATIONS_ROWS][MAP_LOCATIONS_COLS], MatrixPos currentMatrixPos) {
	int row = currentMatrixPos.row;
	int col = currentMatrixPos.col;
	for (int j = col + 1; j < MAP_LOCATIONS_COLS; ++j) {
		if (gameScenes[row][j] != NULL) {
			return true;
		}
	}
	return false;
}

bool canMoveLeft(Texture* gameScenes[MAP_LOCATIONS_ROWS][MAP_LOCATIONS_COLS], MatrixPos currentMatrixPos) {
	int row = currentMatrixPos.row;
	int col = currentMatrixPos.col;
	for (int j = col - 1; j > -1; --j) {
		if (gameScenes[row][j] != NULL) {
			return true;
		}
	}
	return false;
}

bool canMoveUp(Texture* gameScenes[MAP_LOCATIONS_ROWS][MAP_LOCATIONS_COLS], MatrixPos currentMatrixPos) {
	int row = currentMatrixPos.row;
	int col = currentMatrixPos.col;
	for (int i = row - 1; i > -1; --i) {
		if (gameScenes[i][col] != NULL) {
			return true;
		}
	}
	return false;
}

bool canMoveDown(Texture* gameScenes[MAP_LOCATIONS_ROWS][MAP_LOCATIONS_COLS], MatrixPos currentMatrixPos) {
	int row = currentMatrixPos.row;
	int col = currentMatrixPos.col;
	for (int i = row + 1; i < MAP_LOCATIONS_ROWS; ++i) {
		if (gameScenes[i][col] != NULL) {
			return true;
		}
	}
	return false;
}

//get index of where to move player to (first non NULL square)
MatrixPos getMoveRight(Texture* gameScenes[MAP_LOCATIONS_ROWS][MAP_LOCATIONS_COLS], MatrixPos currentMatrixPos) {
	MatrixPos newPos = { currentMatrixPos.row, currentMatrixPos.col };

	int row = currentMatrixPos.row;
	int col = currentMatrixPos.col;
	for (int j = col+1; j < MAP_LOCATIONS_COLS; ++j) {
		if (gameScenes[row][j] != NULL) {
			newPos.col = j;
			return newPos; 
		}
	}
	return newPos; 
}

MatrixPos getMoveLeft(Texture* gameScenes[MAP_LOCATIONS_ROWS][MAP_LOCATIONS_COLS], MatrixPos currentMatrixPos) {
	MatrixPos newPos = { currentMatrixPos.row, currentMatrixPos.col };

	int row = currentMatrixPos.row;
	int col = currentMatrixPos.col;
	for (int j = col-1; j > -1; --j) {
		if (gameScenes[row][j] != NULL) {
			newPos.col = j;
			return newPos;
		}
	}
	return newPos;
}

MatrixPos getMoveUp(Texture* gameScenes[MAP_LOCATIONS_ROWS][MAP_LOCATIONS_COLS], MatrixPos currentMatrixPos) {
	MatrixPos newPos = { currentMatrixPos.row, currentMatrixPos.col };

	int row = currentMatrixPos.row;
	int col = currentMatrixPos.col;
	for (int i = row - 1; i > -1; --i) {
		if (gameScenes[i][col] != NULL) {
			newPos.row = i;
			return newPos;
		}
	}
	return newPos;
}

MatrixPos getMoveDown(Texture* gameScenes[MAP_LOCATIONS_ROWS][MAP_LOCATIONS_COLS], MatrixPos currentMatrixPos) {
	MatrixPos newPos = { currentMatrixPos.row, currentMatrixPos.col };
	
	int row = currentMatrixPos.row;
	int col = currentMatrixPos.col;
	for (int i = row + 1; i < MAP_LOCATIONS_ROWS; ++i) {
		if (gameScenes[i][col] != NULL) {
			newPos.row = i; 
			return newPos;
		}
	}
	return newPos;
}


int main()
{

	const int screenWidth = 1920;
	const int screenHeight = 1080;

	InitWindow(screenWidth, screenHeight, "raylib - project_name");

	//Images

	//TODO: load arc_triomphe.jpg, champs_elysees.jpg

	//Map navigation images
	Image tourEiffel = LoadImage("../assets/tour_eiffel.jpg");
	ImageResize(&tourEiffel, screenWidth - (screenWidth * 0.10), screenHeight - (screenHeight * 0.10));

	Image louvreGallery = LoadImage("../assets/louvre_gallery.jpg");
	ImageResize(&louvreGallery, screenWidth - (screenWidth * 0.10), screenHeight - (screenHeight * 0.10));

	Image moulineRouge = LoadImage("../assets/mouline_rouge_inside.png");
	ImageResize(&moulineRouge, screenWidth - (screenWidth * 0.10), screenHeight - (screenHeight * 0.10));

	Image arcTriomphe = LoadImage("../assets/arc_triomphe.jpg");
	ImageResize(&arcTriomphe, screenWidth - (screenWidth * 0.10), screenHeight - (screenHeight * 0.10));

	Image champsElysees = LoadImage("../assets/champs_elysees.jpg");
	ImageResize(&champsElysees, screenWidth - (screenWidth * 0.10), screenHeight - (screenHeight * 0.10));

	Image hotelInvalides = LoadImage("../assets/hotel_invalides.jpg");
	ImageResize(&hotelInvalides, screenWidth - (screenWidth * 0.10), screenHeight - (screenHeight * 0.10));

	Image placeConcorde = LoadImage("../assets/place-concorde.jpg");
	ImageResize(&placeConcorde, screenWidth - (screenWidth * 0.10), screenHeight - (screenHeight * 0.10));

	Image palaisGarnier = LoadImage("../assets/palais-garnier.jpg");
	ImageResize(&palaisGarnier, screenWidth - (screenWidth * 0.10), screenHeight - (screenHeight * 0.10));

	Image montmatrePlaceTetre = LoadImage("../assets/montmatre_place_du_tetre.jpg");
	ImageResize(&montmatrePlaceTetre, screenWidth - (screenWidth * 0.10), screenHeight - (screenHeight * 0.10));

	Image montmatreStreet = LoadImage("../assets/montmatre.jpg");
	ImageResize(&montmatreStreet, screenWidth - (screenWidth * 0.10), screenHeight - (screenHeight * 0.10));

	Image sacreCouerStairs = LoadImage("../assets/sacre-couer-stairs-3.jpg");
	ImageResize(&sacreCouerStairs, screenWidth - (screenWidth * 0.10), screenHeight - (screenHeight * 0.10));

	Image moulineRougeExt = LoadImage("../assets/mouling_rouge_ext.jpg");
	ImageResize(&moulineRougeExt, screenWidth - (screenWidth * 0.10), screenHeight - (screenHeight * 0.10));

	Image louvrePyramid = LoadImage("../assets/louvre_pyramid.jpg");
	ImageResize(&louvrePyramid, screenWidth - (screenWidth * 0.10), screenHeight - (screenHeight * 0.10));

	Image saintChapelle = LoadImage("../assets/saint_chapelle.jpg");
	ImageResize(&saintChapelle, screenWidth - (screenWidth * 0.10), screenHeight - (screenHeight * 0.10));

	Image pantheon = LoadImage("../assets/pantheon.jpg");
	ImageResize(&pantheon, screenWidth - (screenWidth * 0.10), screenHeight - (screenHeight * 0.10));

	Image notreDame = LoadImage("../assets/notre_dame.jpg");
	ImageResize(&notreDame, screenWidth - (screenWidth * 0.10), screenHeight - (screenHeight * 0.10));

	Image monaLisa = LoadImage("../assets/mona_lisa.jpg");
	ImageResize(&monaLisa, screenWidth - (screenWidth * 0.10), screenHeight - (screenHeight * 0.10));

	Image sacreCouerInside = LoadImage("../assets/sacre-couer-inside.jpg");
	ImageResize(&sacreCouerInside, screenWidth - (screenWidth * 0.10), screenHeight - (screenHeight * 0.10));


	//Characters and utilities images

	Image ciccio = LoadImage("../assets/ciccio.png");
	ImageResize(&ciccio, screenWidth * 0.30, screenHeight * 0.30);

	Image comicDialogRectangle = LoadImage("../assets/comic_dialog_rectangle.png");
	ImageResize(&comicDialogRectangle, screenWidth * 0.40, screenHeight * 0.40);

	Image dogExample = LoadImage("../assets/vito_esempio.png");
	ImageResize(&dogExample, screenWidth * 0.40, screenHeight * 0.40);

	Image dogKisses = LoadImage("../assets/vito_kisses.png");
	ImageResize(&dogKisses, screenWidth * 0.40, screenHeight * 0.40);

	Image leftArrow = LoadImage("../assets/left_arrow.png");
	ImageResize(&leftArrow, screenWidth * 0.10, screenHeight * 0.10);

	Image rightArrow = LoadImage("../assets/right_arrow.png");
	ImageResize(&rightArrow, screenWidth * 0.10, screenHeight * 0.10);

	Image upArrow = LoadImage("../assets/up_arrow.png");
	ImageResize(&upArrow, screenWidth * 0.10, screenHeight * 0.10);

	Image downArrow = LoadImage("../assets/arrow_down.png");
	ImageResize(&downArrow, screenWidth * 0.10, screenHeight * 0.10);

	//Textures 

	//Map navigation textures
	Texture2D tourEiffelTexture = LoadTextureFromImage(tourEiffel);
	Texture2D louvreGalleryTexture = LoadTextureFromImage(louvreGallery);
	Texture2D moulineRougeInsideTexture = LoadTextureFromImage(moulineRouge);
	Texture2D arcTriompheTexture = LoadTextureFromImage(arcTriomphe);
	Texture2D champsElyseesTexture = LoadTextureFromImage(champsElysees);
	Texture2D hotelInvalidesTexture = LoadTextureFromImage(hotelInvalides);
	Texture2D placeConcordeTexture = LoadTextureFromImage(placeConcorde);
	Texture2D palaisGarnierTexture = LoadTextureFromImage(palaisGarnier);
	Texture2D montmatrePlaceTetreTexture = LoadTextureFromImage(montmatrePlaceTetre);
	Texture2D montmatreStreetTexture = LoadTextureFromImage(montmatreStreet);
	Texture2D sacreCouerStairsTexture = LoadTextureFromImage(sacreCouerStairs);
	Texture2D moulineRougeExtTexture = LoadTextureFromImage(moulineRougeExt);
	Texture2D louvrePyramidTexture = LoadTextureFromImage(louvrePyramid);
	Texture2D saintChapelleTexture = LoadTextureFromImage(saintChapelle);
	Texture2D pantheonTexture = LoadTextureFromImage(pantheon);
	Texture2D notreDameTexture = LoadTextureFromImage(notreDame);
	Texture2D monaLisaTexture = LoadTextureFromImage(monaLisa);
	Texture2D sacreCouerInsideTexture = LoadTextureFromImage(sacreCouerInside);

	//Characters and utilities textures
	Texture2D ciccioTexture = LoadTextureFromImage(ciccio);
	Texture2D comicDialogRectangleTexture = LoadTextureFromImage(comicDialogRectangle);
	Texture2D dogExampleTexture = LoadTextureFromImage(dogExample);
	Texture2D dogKissesTexture = LoadTextureFromImage(dogKisses);
	Texture2D leftArrowTexture = LoadTextureFromImage(leftArrow);
	Texture2D rightArrowTexture = LoadTextureFromImage(rightArrow);
	Texture2D upArrowTexture = LoadTextureFromImage(upArrow);
	Texture2D downArrowTexture = LoadTextureFromImage(downArrow);

	UnloadImage(tourEiffel);
	UnloadImage(louvreGallery);
	UnloadImage(arcTriomphe);
	UnloadImage(champsElysees);
	UnloadImage(hotelInvalides);
	UnloadImage(placeConcorde);
	UnloadImage(palaisGarnier);
	UnloadImage(montmatrePlaceTetre);
	UnloadImage(montmatreStreet);
	UnloadImage(sacreCouerStairs);
	UnloadImage(moulineRougeExt);
	UnloadImage(louvrePyramid);
	UnloadImage(saintChapelle);
	UnloadImage(pantheon);
	UnloadImage(notreDame);
	UnloadImage(monaLisa);
	UnloadImage(sacreCouerInside);

	UnloadImage(ciccio);
	UnloadImage(comicDialogRectangle);
	UnloadImage(dogExample);
	UnloadImage(dogKisses);
	UnloadImage(leftArrow);
	UnloadImage(rightArrow);
	UnloadImage(upArrow);
	UnloadImage(downArrow);

	SetTargetFPS(60);

	//Music handling
	InitAudioDevice();
	Music music = LoadMusicStream("../assets/madame_sophie.mp3");
	PlayMusicStream(music);

	enum Screen {
		MAIN_TITLE_1,
		INTRO,
		GAMEPLAY_1,
		ENDING
	};

	//Main screen
	enum Screen screen = MAIN_TITLE_1;

	//Fonts loading
	Font gaglianeFont = LoadFont("../assets/La-Gagliane.otf");
	Font parisienneFont = LoadFont("../assets/Parisienne-Regular.ttf");
	Font obrigeFont = LoadFont("../assets/La-Obrige.otf");
	Font parisishFont = LoadFont("../assets/Parisish.ttf");

	const float titlesSize = 150.0;
	const float fontSpacing = 0.0;

	//Game Title
	const char* mainTitle = "Le avventure di Ciccio Attina'";
	Vector2 mainTitleMeas = MeasureTextEx(gaglianeFont, mainTitle, titlesSize, fontSpacing);
	Vector2 mainTitlePos = { (screenWidth - mainTitleMeas.x) / 2, screenHeight * 0.20 + mainTitleMeas.y };

	//Subitle
	const char* subtitle = "Ep.1: Parigi";
	Vector2 subtitleMeas = MeasureTextEx(parisishFont, subtitle, titlesSize, fontSpacing);
	Vector2 subtitlePos = { (screenWidth - subtitleMeas.x) / 2, mainTitlePos.y };

	//Credits 1
	const char* credits1 = "Soggetto e sceneggiatura";
	Vector2 credits1Meas = MeasureTextEx(parisishFont, credits1, titlesSize, fontSpacing);
	Vector2 credits1Pos = { (screenWidth - credits1Meas.x) / 2 + screenWidth * 0.05, mainTitlePos.y };

	const char* credits2 = "Antonino Cilione";
	Vector2 credits2Meas = MeasureTextEx(parisishFont, credits2, titlesSize, fontSpacing);
	Vector2 credits2Pos = { (screenWidth - credits2Meas.x) / 2, mainTitlePos.y };

	const char* credits3 = "Con la partecipazione straordinaria di";
	Vector2 credits3Meas = MeasureTextEx(parisishFont, credits3, titlesSize, fontSpacing);
	Vector2 credits3Pos = { ((screenWidth - credits3Meas.x) / 2 + 150) , mainTitlePos.y };

	const char* credits4 = "Vito";
	Vector2 credits4Meas = MeasureTextEx(parisishFont, credits4, titlesSize, fontSpacing);
	Vector2 credits4Pos = { (screenWidth - credits4Meas.x) / 2, mainTitlePos.y };

	const char* credits5 = "Starring";
	Vector2 credits5Meas = MeasureTextEx(parisishFont, credits5, titlesSize, fontSpacing);
	Vector2 credits5Pos = { (screenWidth - credits5Meas.x) / 2, mainTitlePos.y };

	const char* credits6 = "Ciccio Attina'";
	Vector2 credits6Meas = MeasureTextEx(parisishFont, credits6, titlesSize, fontSpacing);
	Vector2 credits6Pos = { (screenWidth - credits6Meas.x) / 2, mainTitlePos.y };

	//Play Button Rectangle
	float playBtnWidth = 400.0;
	float playBtnHeigth = 200.0;

	Vector2 playBtnPos = { (screenWidth - playBtnWidth) / 2 , screenHeight * 0.80 - playBtnHeigth };
	Rectangle rect = { playBtnPos.x, playBtnPos.y, playBtnWidth, playBtnHeigth };

	float rectRoundnes = 5.0;
	float rectSegments = 0.0;

	//Continue Button Text 1
	const char* continueBtnTxt = "Continua";
	const float continueBtnTxtSize = 100.0;
	Vector2 continueBtnTxtMeas = MeasureTextEx(gaglianeFont, continueBtnTxt, continueBtnTxtSize, fontSpacing);
	Vector2 continueBtnTxtPos = { (playBtnPos.x + (playBtnWidth - continueBtnTxtMeas.x) / 2), playBtnPos.y + playBtnHeigth * 0.30 };

	//Continue Button Text 2
	const char* playBtnTxt = "Fai l'elicottero";
	const float playBtnTxtSize = 100.0;
	Vector2 playBtnTxtMeas = MeasureTextEx(gaglianeFont, playBtnTxt, continueBtnTxtSize, fontSpacing);
	Vector2 playBtnTxtPos = { (playBtnPos.x + (playBtnWidth - playBtnTxtMeas.x) / 2), playBtnPos.y + playBtnHeigth * 0.30 };


	//Button TOP
	Vector2 gameplayDialogueContinueBtnPos = { (screenWidth - playBtnWidth) / 2, screenHeight * 0.30 - playBtnHeigth };
	Rectangle gameplayDialogueContinueBtn = { gameplayDialogueContinueBtnPos.x, gameplayDialogueContinueBtnPos.y, playBtnWidth, playBtnHeigth };

	//Continue Text Button TOP
	const char* continueBtnTopTxt = "Continua";
	const float continueBtnTopTxtSize = 100.0;
	Vector2 continueBtnTopTxtMeas = MeasureTextEx(gaglianeFont, continueBtnTopTxt, continueBtnTopTxtSize, fontSpacing);
	Vector2 continueBtnTopTxtPos = { (gameplayDialogueContinueBtnPos.x + (playBtnWidth - continueBtnTxtMeas.x) / 2), gameplayDialogueContinueBtnPos.y + playBtnHeigth * 0.30 };

	//Ciccio Texture
	Vector2 ciccioPos = { screenWidth * 0.45, screenHeight / 2 - tourEiffelTexture.height / 2 + tourEiffelTexture.height - ciccioTexture.height };

	//Comic Dialogue Rectangle Texture
	Vector2 comicDialogRectangleTexturePos = { ciccioPos.x - screenWidth * 0.33, ciccioPos.y - screenHeight * 0.28 };
	Vector2 endingComicDialogRectangleTexturePos = { ciccioPos.x - screenWidth * 0.33, ciccioPos.y - screenHeight * 0.40 };
	Vector2 endingComicDialogPos = { endingComicDialogRectangleTexturePos.x + endingComicDialogRectangleTexturePos.x * 0.20, endingComicDialogRectangleTexturePos.y + endingComicDialogRectangleTexturePos.y  * 0.30 };

	//Dog example Texture
	Vector2 dogExampleTexturePos = { comicDialogRectangleTexturePos.x + 200, comicDialogRectangleTexturePos.y + 200 };

	//Comic Dialogue Text
	const char* dialogue1Txt = "Ciao, sono Ciccio!";
	const float dialogue1TxtSize = 100.0;
	Vector2 dialogue1TxtMeas = MeasureTextEx(gaglianeFont, dialogue1Txt, dialogue1TxtSize, fontSpacing);
	Vector2 dialogue1TxtPos = { comicDialogRectangleTexturePos.x + (comicDialogRectangleTexture.width - dialogue1TxtMeas.x) / 2, comicDialogRectangleTexturePos.y + comicDialogRectangleTexture.height * 0.30 };

	const char* dialogue2Txt = "Oggi mi trovo\n a Parigi!";
	const float dialogue2TxtSize = 100.0;
	Vector2 dialogue2TxtMeas = MeasureTextEx(gaglianeFont, dialogue2Txt, dialogue2TxtSize, fontSpacing);
	Vector2 dialogue2TxtPos = { comicDialogRectangleTexturePos.x + (comicDialogRectangleTexture.width - dialogue2TxtMeas.x) / 2, comicDialogRectangleTexturePos.y + comicDialogRectangleTexture.height * 0.30 - 55 };

	const char* dialogue3Txt = "Stavo pensando se\n fare l'elicottero...";
	const float dialogue3TxtSize = 100.0;
	Vector2 dialogue3TxtMeas = MeasureTextEx(gaglianeFont, dialogue3Txt, dialogue3TxtSize, fontSpacing);
	Vector2 dialogue3TxtPos = { comicDialogRectangleTexturePos.x + (comicDialogRectangleTexture.width - dialogue3TxtMeas.x) / 2, comicDialogRectangleTexturePos.y + comicDialogRectangleTexture.height * 0.30 - 55 };

	const char* dialogue4Txt = "...e ho perso\n il mio cane.";
	const float dialogue4TxtSize = 100.0;
	Vector2 dialogue4TxtMeas = MeasureTextEx(gaglianeFont, dialogue4Txt, dialogue4TxtSize, fontSpacing);
	Vector2 dialogue4TxtPos = { comicDialogRectangleTexturePos.x + (comicDialogRectangleTexture.width - dialogue4TxtMeas.x) / 2, comicDialogRectangleTexturePos.y + comicDialogRectangleTexture.height * 0.30 - 55 };

	const char* dialogue5Txt = "Per favore, aiutami\n a trovarlo!";
	const float dialogue5TxtSize = 100.0;
	Vector2 dialogue5TxtMeas = MeasureTextEx(gaglianeFont, dialogue5Txt, dialogue5TxtSize, fontSpacing);
	Vector2 dialogue5TxtPos = { comicDialogRectangleTexturePos.x + (comicDialogRectangleTexture.width - dialogue5TxtMeas.x) / 2, comicDialogRectangleTexturePos.y + comicDialogRectangleTexture.height * 0.30 - 55 };

	const char* dialogue6Txt = "E' questo qui:";
	const float dialogue6TxtSize = 100.0;
	Vector2 dialogue6TxtMeas = MeasureTextEx(gaglianeFont, dialogue6Txt, dialogue6TxtSize, fontSpacing);
	Vector2 dialogue6TxtPos = { comicDialogRectangleTexturePos.x + (comicDialogRectangleTexture.width - dialogue6TxtMeas.x) / 2, comicDialogRectangleTexturePos.y + comicDialogRectangleTexture.height * 0.30 - 55 };

	const char* dialogue7Txt = "In bocca al lupo!";
	const float dialogue7TxtSize = 100.0;
	Vector2 dialogue7TxtMeas = MeasureTextEx(gaglianeFont, dialogue7Txt, dialogue7TxtSize, fontSpacing);
	Vector2 dialogue7TxtPos = { comicDialogRectangleTexturePos.x + (comicDialogRectangleTexture.width - dialogue7TxtMeas.x) / 2, comicDialogRectangleTexturePos.y + comicDialogRectangleTexture.height * 0.30 - 55 };

	//ending ciccio dialogues props
	const char* endingCiccioDialogue1Txt = "Vituuuzzo! Ma dove\n te n'eri andato!";
	const float endingCiccioDialogue1Size = 100.0;
	Vector2 endingCiccioDialogue1Meas = MeasureTextEx(gaglianeFont, endingCiccioDialogue1Txt, endingCiccioDialogue1Size, fontSpacing);
	Vector2 endingCiccioDialogue1Pos = { comicDialogRectangleTexturePos.x + (comicDialogRectangleTexture.width - endingCiccioDialogue1Meas.x) / 2, comicDialogRectangleTexturePos.y + comicDialogRectangleTexture.height * 0.30 - 55 };


	//Navigation Arrows

	//TODO: refactor with texture pos variable
	Rectangle leftArrowRect = { screenWidth * 0.10, screenHeight / 2 - leftArrowTexture.height / 2, leftArrowTexture.width, leftArrowTexture.height };
	Rectangle rightArrowRect = { screenWidth * 0.80, screenHeight / 2 - rightArrowTexture.height / 2, rightArrowTexture.width, rightArrowTexture.height };
	Rectangle upArrowRect = { screenWidth / 2, screenHeight * 0.10, upArrowTexture.width, upArrowTexture.height };
	Rectangle downArrowRect = { screenWidth / 2, screenHeight * 0.80, downArrowTexture.width, downArrowTexture.height};

	Vector2 mousePos;

	typedef struct {
		Font font;
		char* text;
		Vector2 position;
		float fontSize;
		float spacing;
		Color tint;
	} DrawTextExParams;

	const DrawTextExParams mainTitles[MAIN_TITLE_ARR_LEN] = {
		{ gaglianeFont, mainTitle, mainTitlePos, titlesSize, fontSpacing, RED },
		{ parisienneFont, subtitle, subtitlePos, titlesSize, fontSpacing, RED },
		{ parisienneFont, credits1, credits1Pos, titlesSize, fontSpacing, RED },
		{ parisienneFont, credits2, credits2Pos, titlesSize, fontSpacing, RED },
		{ parisienneFont, credits3, credits3Pos, titlesSize, fontSpacing, RED },
		{ parisienneFont, credits4, credits4Pos, titlesSize, fontSpacing, RED },
		{ parisienneFont, credits5, credits5Pos, titlesSize, fontSpacing, RED },
		{ parisienneFont, credits6, credits6Pos, titlesSize, fontSpacing, RED },
	};

	const DrawTextExParams introCiccioDialogues[CICCIO_DIALOGUES_SCREEN_INTRO_ARR_LEN] = {
		{ parisienneFont, dialogue1Txt, dialogue1TxtPos, dialogue1TxtSize, fontSpacing, BLUE },
		{ parisienneFont, dialogue2Txt, dialogue2TxtPos, dialogue2TxtSize, fontSpacing, BLUE },
		{ parisienneFont, dialogue3Txt, dialogue3TxtPos, dialogue3TxtSize, fontSpacing, BLUE },
		{ parisienneFont, dialogue4Txt, dialogue4TxtPos, dialogue4TxtSize, fontSpacing, BLUE },
		{ parisienneFont, dialogue5Txt, dialogue5TxtPos, dialogue5TxtSize, fontSpacing, BLUE },
		{ parisienneFont, dialogue6Txt, dialogue6TxtPos, dialogue6TxtSize, fontSpacing, BLUE },
		{ parisienneFont, dialogue7Txt, dialogue7TxtPos, dialogue7TxtSize, fontSpacing, BLUE },
	};


	//Init locations map for navigation



	//State variables
	int mainTitlesIdx = 0;
	int introCiccioDialoguesIdx = 0;
	int endingCiccioDialoguesIdx = 0;

	bool isBtnHovered = false;
	Color btnTxtColor = BLUE;

	//handle navigation 
	bool isLeftArrowHovered = false;
	bool isRightArrowHovered = false;
	bool isUpArrowHovered = false;
	bool isDownArrowHovered = false; 

	int gameScenesIdx = 0;

	Texture* gameScenes[MAP_LOCATIONS_ROWS][MAP_LOCATIONS_COLS] = { NULL };

	Rectangle dogBox = { moulineRougeInsideTexture.width * 0.425, moulineRougeInsideTexture.height * 0.67, moulineRougeInsideTexture.width * 0.03, moulineRougeInsideTexture.height * 0.05 };

	gameScenes[5][0] = &arcTriompheTexture;
	gameScenes[9][0] = &champsElyseesTexture;
	gameScenes[10][0] = &tourEiffelTexture;

	gameScenes[3][1] = &moulineRougeInsideTexture;
	gameScenes[4][1] = &moulineRougeExtTexture;

	gameScenes[0][2] = &sacreCouerInsideTexture;
	gameScenes[1][2] = &sacreCouerStairsTexture;
	gameScenes[2][2] = &montmatreStreetTexture;
	gameScenes[4][2] = &montmatrePlaceTetreTexture;
	gameScenes[5][2] = &palaisGarnierTexture;
	gameScenes[9][2] = &placeConcordeTexture;
	gameScenes[10][2] = &hotelInvalidesTexture;

	//add orsay col 3 

	gameScenes[7][4] = &monaLisaTexture;
	gameScenes[8][4] = &louvreGalleryTexture;
	gameScenes[10][4] = &louvrePyramidTexture;

	gameScenes[10][5] = &saintChapelleTexture;
	gameScenes[11][5] = &pantheonTexture;
	gameScenes[10][6] = &notreDameTexture;

	//map matrix player position
	MatrixPos currentPlayerPos = { 10, 0 }; //tourEiffel 

	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		if (IsMusicStreamPlaying(music)) {
			UpdateMusicStream(music);
		}

		mousePos = GetMousePosition();

		BeginDrawing();
		ClearBackground(RAYWHITE);

		DrawRectangleLines(screenWidth / 2 - tourEiffelTexture.width / 2, screenHeight / 2 - tourEiffelTexture.height / 2, tourEiffelTexture.width, tourEiffelTexture.height, DARKGRAY);

		switch (screen) {
		case MAIN_TITLE_1: {
			DrawTexture(tourEiffelTexture, screenWidth / 2 - tourEiffelTexture.width / 2, screenHeight / 2 - tourEiffelTexture.height / 2, WHITE);

			DrawTextEx(
				mainTitles[mainTitlesIdx].font,
				mainTitles[mainTitlesIdx].text,
				mainTitles[mainTitlesIdx].position,
				mainTitles[mainTitlesIdx].fontSize,
				mainTitles[mainTitlesIdx].spacing,
				mainTitles[mainTitlesIdx].tint
			);

			//Draw play button
			DrawRectangleRounded(rect, rectRoundnes, (int)rectSegments, Fade(YELLOW, 0.3f));

			isBtnHovered = CheckCollisionPointRec(mousePos, rect);
			btnTxtColor = isBtnHovered ? RED : BLUE;

			if (mainTitlesIdx == MAIN_TITLE_ARR_LEN - 1) {
				DrawTextEx(parisienneFont, playBtnTxt, playBtnTxtPos, playBtnTxtSize, fontSpacing, btnTxtColor);

				if (isBtnHovered && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
					screen = INTRO;
				}
			}
			else {
				DrawTextEx(parisienneFont, continueBtnTxt, continueBtnTxtPos, continueBtnTxtSize, fontSpacing, btnTxtColor);
				if (isBtnHovered && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && mainTitlesIdx < MAIN_TITLE_ARR_LEN - 1) {
					mainTitlesIdx++;
				}
			}
			break;
		}
		case INTRO: {
			DrawTexture(tourEiffelTexture, screenWidth / 2 - tourEiffelTexture.width / 2, screenHeight / 2 - tourEiffelTexture.height / 2, WHITE);

			isBtnHovered = CheckCollisionPointRec(mousePos, gameplayDialogueContinueBtn);
			btnTxtColor = isBtnHovered ? RED : BLUE;

			DrawTexture(ciccioTexture, ciccioPos.x, ciccioPos.y, WHITE);
			DrawTexture(comicDialogRectangleTexture, comicDialogRectangleTexturePos.x, comicDialogRectangleTexturePos.y, WHITE);

			DrawTextEx(
				introCiccioDialogues[introCiccioDialoguesIdx].font,
				introCiccioDialogues[introCiccioDialoguesIdx].text,
				introCiccioDialogues[introCiccioDialoguesIdx].position,
				introCiccioDialogues[introCiccioDialoguesIdx].fontSize,
				introCiccioDialogues[introCiccioDialoguesIdx].spacing,
				introCiccioDialogues[introCiccioDialoguesIdx].tint
			);

			DrawRectangleRounded(gameplayDialogueContinueBtn, rectRoundnes, (int)rectSegments, Fade(YELLOW, 0.3f));
			DrawTextEx(parisienneFont, continueBtnTxt, continueBtnTopTxtPos, continueBtnTopTxtSize, fontSpacing, btnTxtColor);
			

			if (isBtnHovered && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && introCiccioDialoguesIdx < CICCIO_DIALOGUES_SCREEN_INTRO_ARR_LEN - 1) {
				introCiccioDialoguesIdx++;
			}

			if (introCiccioDialoguesIdx == 5) {
				DrawTexture(dogExampleTexture, dogExampleTexturePos.x, dogExampleTexturePos.y, WHITE);
			}

			if (isBtnHovered && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && introCiccioDialoguesIdx == CICCIO_DIALOGUES_SCREEN_INTRO_ARR_LEN - 1) {
				screen = GAMEPLAY_1;
			}

			break;
		}
		case GAMEPLAY_1: {

			DrawTexture(*gameScenes[currentPlayerPos.row][currentPlayerPos.col], screenWidth / 2 - louvreGalleryTexture.width / 2, screenHeight / 2 - louvreGalleryTexture.height / 2, WHITE);

			//check for which arrows to render and in case make the interactive
			if (canMoveLeft(gameScenes, currentPlayerPos)) {

				DrawTexture(leftArrowTexture, screenWidth * 0.10, screenHeight / 2 - leftArrowTexture.height / 2, WHITE);
				isLeftArrowHovered = CheckCollisionPointRec(mousePos, leftArrowRect);

				if (isLeftArrowHovered && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
					//Get index where to move and set player position 
					currentPlayerPos = getMoveLeft(gameScenes, currentPlayerPos);
				}
			} 
			if (canMoveRight(gameScenes, currentPlayerPos)) {
				DrawTexture(rightArrowTexture, screenWidth * 0.80, screenHeight / 2 - rightArrowTexture.height / 2, WHITE);
				isRightArrowHovered = CheckCollisionPointRec(mousePos, rightArrowRect);
				
				if (isRightArrowHovered && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
					currentPlayerPos = getMoveRight(gameScenes, currentPlayerPos); 
				}
			}

			if (canMoveUp(gameScenes, currentPlayerPos)) {
				DrawTexture(upArrowTexture, upArrowRect.x, upArrowRect.y, WHITE);

				isUpArrowHovered = CheckCollisionPointRec(mousePos, upArrowRect); 
				
				if (isUpArrowHovered && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
					currentPlayerPos = getMoveUp(gameScenes, currentPlayerPos);
				}
			}

			if (canMoveDown(gameScenes, currentPlayerPos)) {
				DrawTexture(downArrowTexture, downArrowRect.x, downArrowRect.y, WHITE);

				isDownArrowHovered = CheckCollisionPointRec(mousePos, downArrowRect); 
				
				if (isDownArrowHovered && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
					currentPlayerPos = getMoveDown(gameScenes, currentPlayerPos); 
				}
			}

			//if inside mouline rouge spawn box for win
			//if (currentPlayerPos.row == 3 && currentPlayerPos.col == 1) {
			//	DrawRectangleLines(dogBox.x, dogBox.y, dogBox.width, dogBox.height, GREEN); //draw only for debug purposes
			//}

			if (currentPlayerPos.row == 3 && currentPlayerPos.col == 1 && CheckCollisionPointRec(mousePos, dogBox) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
				//TODO: add dog and win sound. wait for the sound to stop before moving to ending screen
				screen = ENDING;
			}

			break;
		}
		case ENDING: {
			DrawTexture(tourEiffelTexture, screenWidth / 2 - tourEiffelTexture.width / 2, screenHeight / 2 - tourEiffelTexture.height / 2, WHITE);

			isBtnHovered = CheckCollisionPointRec(mousePos, gameplayDialogueContinueBtn);
			btnTxtColor = isBtnHovered ? RED : BLUE;

			DrawTexture(ciccioTexture, ciccioPos.x, ciccioPos.y, WHITE);
			DrawTexture(comicDialogRectangleTexture, endingComicDialogRectangleTexturePos.x, endingComicDialogRectangleTexturePos.y, WHITE);
			DrawTexture(dogKissesTexture, dogExampleTexturePos.x, dogExampleTexturePos.y, WHITE);
			DrawTextEx(parisienneFont, endingCiccioDialogue1Txt, endingComicDialogPos, endingCiccioDialogue1Size, fontSpacing, BLUE);
			break;
		}
		}
		EndDrawing();
	}

	UnloadTexture(tourEiffelTexture);
	UnloadTexture(louvreGalleryTexture);
	UnloadTexture(moulineRougeInsideTexture);
	UnloadTexture(arcTriompheTexture);
	UnloadTexture(champsElyseesTexture);
	UnloadTexture(hotelInvalidesTexture);
	UnloadTexture(placeConcordeTexture);
	UnloadTexture(palaisGarnierTexture);
	UnloadTexture(montmatrePlaceTetreTexture);
	UnloadTexture(montmatreStreetTexture);
	UnloadTexture(sacreCouerStairsTexture);
	UnloadTexture(moulineRougeExtTexture);
	UnloadTexture(louvrePyramidTexture);
	UnloadTexture(saintChapelleTexture);
	UnloadTexture(pantheonTexture);
	UnloadTexture(notreDameTexture);
	UnloadTexture(monaLisaTexture);
	UnloadTexture(sacreCouerInsideTexture);

	UnloadTexture(ciccioTexture);
	UnloadTexture(comicDialogRectangleTexture);
	UnloadTexture(dogExampleTexture);
	UnloadTexture(dogKissesTexture);
	UnloadTexture(leftArrowTexture);
	UnloadTexture(rightArrowTexture);
	UnloadTexture(upArrowTexture);
	UnloadTexture(downArrowTexture);
	
	UnloadMusicStream(music);
	CloseAudioDevice();

	CloseWindow();

	return 0;
}


