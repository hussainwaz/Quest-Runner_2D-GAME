#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include <iostream>
#include<fstream>
using namespace std;
using namespace sf;

//------------------------------------------------------------Level 1 -----------------------------------------------------------
struct Obstacle_level1 {
	Sprite sprite_level1;
	Vector2f position_level1;
	float speed_level1;

	Obstacle_level1(Texture& texture, const Vector2f& initialPosition, float obstacleSpeed)
		: position_level1(initialPosition), speed_level1(obstacleSpeed) {
		sprite_level1.setTexture(texture);
		sprite_level1.setPosition(460, 1300);
		sprite_level1.setScale(0.4f, 0.4f);
	}

	void move_level1(float elapsedTime) {
		position_level1.x -= speed_level1 * elapsedTime;
		sprite_level1.setPosition(position_level1);
	}
};
//------------------------------------------------------End of level 1 ----------------------------------------------------------

//------------------------------------------------------------Level 2 -----------------------------------------------------------

struct Obstacle_level2 {
	Sprite sprite_level2;
	Vector2f position_level2;
	float speed_level2;

	Obstacle_level2(Texture& texture, const Vector2f& initialPosition, float obstacleSpeed)
		: position_level2(initialPosition), speed_level2(obstacleSpeed) {
		sprite_level2.setTexture(texture);
		sprite_level2.setPosition(460, 1300);
		sprite_level2.setScale(0.4f, 0.4f);
	}

	void move_level2(float elapsedTime) {
		position_level2.x -= speed_level2 * elapsedTime;
		sprite_level2.setPosition(position_level2);
	}
};


//------------------------------------------------------End of level 2 ----------------------------------------------------------


//------------------------------------------------------------Level 3 -----------------------------------------------------------
struct Obstacle_level3 {
	Sprite sprite_level3;
	Vector2f position_level3;
	float speed_level3;

	Obstacle_level3(Texture& texture, const Vector2f& initialPosition, float obstacleSpeed)
		: position_level3(initialPosition), speed_level3(obstacleSpeed) {
		sprite_level3.setTexture(texture);
		sprite_level3.setPosition(460, 1300);
		sprite_level3.setScale(0.4f, 0.4f);
	}

	void move_level3(float elapsedTime) {
		position_level3.x -= speed_level3 * elapsedTime;
		sprite_level3.setPosition(position_level3);
	}
};
//------------------------------------------------------End of level 3 ----------------------------------------------------------


int main()
{
	RenderWindow window(VideoMode(1500, 900), "Quest Runner", Style::Default);
	window.setFramerateLimit(60);
	//obstacles
	bool obstaclespawn_level1 = false;
	bool obstaclespawn_level2 = false;
	bool obstaclespawn_level3 = false;
	//file handling
	ifstream in;
	ofstream out;
	int highscore;
	//___________
	
	//Texture 1
	Texture showup1;
	if (!showup1.loadFromFile("pic/showup/1.png"))
	{
		cout << "Layer1 not loaded" << endl;
		return EXIT_FAILURE;
	}
	Sprite layer1_showup;
	layer1_showup.setTexture(showup1);
	layer1_showup.setScale((float)window.getSize().x / showup1.getSize().x, (float)window.getSize().y / showup1.getSize().y);
	layer1_showup.setPosition(0, 0);
	float layer1_showup_speed = 3.0f;
	//Texture 1 copy
	Texture showup1copy;
	if (!showup1copy.loadFromFile("pic/showup/1copy.png"))
	{
		cout << "Layer1 copy not loaded" << endl;
		return EXIT_FAILURE;
	}
	Sprite layer1_showup_copy;
	layer1_showup_copy.setTexture(showup1copy);
	layer1_showup_copy.setScale((float)window.getSize().x / showup1.getSize().x, (float)window.getSize().y / showup1.getSize().y);
	layer1_showup_copy.setPosition(1500, 0);

	//Texture 2
	Texture showup2;
	if (!showup2.loadFromFile("pic/showup/2.png"))
	{
		cout << "Layer2 not loaded" << endl;
		return EXIT_FAILURE;
	}
	Sprite layer2_showup;
	layer2_showup.setTexture(showup2);
	layer2_showup.setScale((float)window.getSize().x / showup2.getSize().x, (float)window.getSize().y / showup2.getSize().y);
	layer2_showup.setPosition(0, 0);
	float layer2_showup_speed = 2.5f;

	//Texture 2 copy
	Texture showup2copy;
	if (!showup2copy.loadFromFile("pic/showup/2copy.png"))
	{
		cout << "Layer2 copy not loaded" << endl;
		return EXIT_FAILURE;
	}
	Sprite layer2_showup_copy;
	layer2_showup_copy.setTexture(showup2copy);
	layer2_showup_copy.setScale((float)window.getSize().x / showup2.getSize().x, (float)window.getSize().y / showup2.getSize().y);
	layer2_showup_copy.setPosition(1500, 0);

	//Texture 3
	Texture showup3;
	if (!showup3.loadFromFile("pic/showup/3.png"))
	{
		cout << "Layer3 not loaded" << endl;
		return EXIT_FAILURE;
	}
	Sprite layer3_showup;
	layer3_showup.setTexture(showup3);
	layer3_showup.setScale((float)window.getSize().x / showup3.getSize().x, (float)window.getSize().y / showup3.getSize().y);
	layer3_showup.setPosition(0, 0);
	float layer3_showup_speed = 3.0f;
	//Texture 3 copy
	Texture showup3copy;
	if (!showup3copy.loadFromFile("pic/showup/3copy.png"))
	{
		cout << "Layer3 copy not loaded" << endl;
		return EXIT_FAILURE;
	}
	Sprite layer3_showup_copy;
	layer3_showup_copy.setTexture(showup3copy);
	layer3_showup_copy.setScale((float)window.getSize().x / showup3.getSize().x, (float)window.getSize().y / showup3.getSize().y);
	layer3_showup_copy.setPosition(1500, 0);

	//logo
	Texture logoTexture;
	if (!logoTexture.loadFromFile("pic/showup/logo.png"))
	{
		return EXIT_FAILURE;
	}
	Sprite logoSprite;
	logoSprite.setTexture(logoTexture);
	logoSprite.setScale(0.3, 0.3);
	logoSprite.setOrigin(logoTexture.getSize().x / 2, logoTexture.getSize().y / 2);
	logoSprite.setPosition((window.getSize().x / 2), (window.getSize().y / 2) - 150);

	Font font;
	if (!font.loadFromFile("pic/showup/font.otf")) {
		return -1;
	}

	Text startText("Start", font, 60);
	startText.setOrigin(startText.getLocalBounds().width / 2, startText.getLocalBounds().height / 2);
	startText.setPosition((window.getSize().x / 2), (window.getSize().y / 2) + 40);
	startText.setFillColor(Color::Yellow);

	Text quitText("Quit", font, 60);
	quitText.setFillColor(Color::Black);
	quitText.setOrigin(quitText.getLocalBounds().width / 2, quitText.getLocalBounds().height / 2);
	quitText.setPosition(window.getSize().x / 2, (window.getSize().y / 2) + 120);

	Text level1Text("Level 01", font, 50);
	level1Text.setOrigin(level1Text.getLocalBounds().width / 2, level1Text.getLocalBounds().height / 2);
	level1Text.setPosition((window.getSize().x / 2) + 350, (window.getSize().y / 2) - 150);
	level1Text.setFillColor(Color::Yellow);

	Text level2Text("Level 02", font, 50);
	level2Text.setOrigin(level2Text.getLocalBounds().width / 2, level2Text.getLocalBounds().height / 2);
	level2Text.setPosition((window.getSize().x / 2) + 350, (window.getSize().y / 2) + 0);
	level2Text.setFillColor(Color::Yellow);

	Text level3Text("Endless Run", font, 50);
	level3Text.setOrigin(level3Text.getLocalBounds().width / 2, level3Text.getLocalBounds().height / 2);
	level3Text.setPosition((window.getSize().x / 2) + 350, (window.getSize().y / 2) + 150);
	level3Text.setFillColor(Color::Yellow);

	Text quit2Text("Quit", font, 60);
	quit2Text.setOrigin(quit2Text.getLocalBounds().width / 2, quit2Text.getLocalBounds().height / 2);
	quit2Text.setPosition(window.getSize().x / 2, (window.getSize().y / 2) + 120);
	quit2Text.setFillColor(Color::Black);

	Text returnText("Back", font, 60);
	returnText.setOrigin(returnText.getLocalBounds().width / 2, returnText.getLocalBounds().height / 2);
	returnText.setPosition(window.getSize().x / 2, (window.getSize().y / 2) + 180);
	returnText.setFillColor(Color::Black);

	Text noteText("Note:", font, 30);
	noteText.setOrigin(noteText.getLocalBounds().width / 2, noteText.getLocalBounds().height / 2);
	noteText.setPosition((window.getSize().x / 2), (window.getSize().y / 2) + 300);
	noteText.setFillColor(Color::Yellow);

	Text note1Text("Maintain a good distance from obstacles or you will end up dead!", font, 30);
	note1Text.setOrigin(note1Text.getLocalBounds().width / 2, (note1Text.getLocalBounds().height / 2));
	note1Text.setPosition((window.getSize().x / 2), ((window.getSize().y / 2) + 345));
	note1Text.setFillColor(Color::White);

	Text pause;
	pause.setString("Paused");
	pause.setFont(font);
	pause.setCharacterSize(60);
	pause.setFillColor(Color::White);
	pause.setPosition((window.getSize().x - pause.getLocalBounds().width) / 2, window.getSize().y / 2 - pause.getLocalBounds().height - 400);

	Text resumeText;
	resumeText.setFont(font);
	resumeText.setCharacterSize(60);
	resumeText.setFillColor(Color::Green);
	resumeText.setString("Resume");
	resumeText.setPosition((window.getSize().x - resumeText.getLocalBounds().width) / 2, pause.getPosition().y + pause.getLocalBounds().height + 50);

	Text back1Text;
	back1Text.setFont(font);
	back1Text.setCharacterSize(60);
	back1Text.setFillColor(Color::White);
	back1Text.setString("Back");
	back1Text.setOrigin(back1Text.getLocalBounds().width / 2, back1Text.getLocalBounds().height / 2);
	back1Text.setPosition((window.getSize().x / 2), (window.getSize().y / 2) - 230);

	Text quit1;
	quit1.setFont(font);
	quit1.setCharacterSize(60);
	quit1.setFillColor(Color::Black);
	quit1.setString("Quit");
	quit1.setOrigin(quit1.getLocalBounds().width / 2, quit1.getLocalBounds().height / 2);
	quit1.setPosition((window.getSize().x / 2), (window.getSize().y / 2) - 160);

	Text gameover;
	gameover.setFont(font);
	gameover.setCharacterSize(60);
	gameover.setFillColor(Color::Yellow);
	gameover.setString("Game Over");
	gameover.setPosition((window.getSize().x / 2), (window.getSize().y / 2) + 40);

	Text restart;
	restart.setFont(font);
	restart.setCharacterSize(60);
	restart.setFillColor(Color::Yellow);
	restart.setString("Restart");
	restart.setPosition(window.getSize().x / 2, (window.getSize().y / 2) + 200);

//You won_____________________
	Text wonText("YOU WON!!!!", font, 60);
	wonText.setOrigin(wonText.getLocalBounds().width / 2, (wonText.getLocalBounds().height / 2));
	wonText.setPosition((window.getSize().x / 2), ((window.getSize().y / 2)));
	wonText.setFillColor(Color::White);

	Text nextLevelText("Next Level -->", font, 30);
	nextLevelText.setOrigin(nextLevelText.getLocalBounds().width / 2, (nextLevelText.getLocalBounds().height / 2));
	nextLevelText.setPosition((window.getSize().x / 2) + 600, ((window.getSize().y / 2)) + 300);
	nextLevelText.setFillColor(Color::White);

	Text scoretext;
	scoretext.setFont(font);
	scoretext.setCharacterSize(40);
	scoretext.setFillColor(Color::Black);
	scoretext.setPosition(10, 10);
	scoretext.setStyle(Text::Bold);

	Text scoreLevel3Text;
	scoreLevel3Text.setFont(font);
	scoreLevel3Text.setCharacterSize(40);
	scoreLevel3Text.setFillColor(Color::Black);
	scoreLevel3Text.setPosition(10, 10);
	scoreLevel3Text.setStyle(Text::Bold);

	Text highScoreText;
	highScoreText.setFont(font);
	highScoreText.setCharacterSize(40);
	highScoreText.setFillColor(Color::Black);
	highScoreText.setPosition(850, 10);
	highScoreText.setStyle(Text::Bold);
	Text highScoreText1;
	highScoreText1.setFont(font);
	highScoreText1.setCharacterSize(40);
	highScoreText1.setFillColor(Color::Black);
	highScoreText1.setPosition(1165, 10);
	highScoreText1.setStyle(Text::Bold);
	//music 
	Music music1;
	if (!music1.openFromFile("music/level1/Sanctuary.WAV"))
	{
		cout << "music not loaded!!!" << endl;
	}
	music1.setVolume(50.f);

	Music music2;
	if (!music2.openFromFile("music/level2/Box Jump.WAV"))
	{
		cout << "mussic not loaded!!!" << endl;
	}
	music2.setVolume(50.f);

	Music music3;
	if (!music3.openFromFile("music/level3/Deep Blue.WAV"))
	{
		cout << "mussic not loaded!!!" << endl;
	}
	music3.setVolume(50.f);
	Music music4;
	if (!music4.openFromFile("music/ghost.WAV"))
	{
		cout << "mussic not loaded!!!" << endl;
	}
	music4.setVolume(80.f);

	//sound effect
	SoundBuffer buffer;
	if (!buffer.loadFromFile("music/explosion3.OGG"))
	{
		cout << "sound effect not loaded" << endl;
	}
	Sound sound;
	sound.setBuffer(buffer);


	bool inMainMenu = true;
	bool inLevelSelection = false;
	bool level1selected = false;
	bool level2selected = false;
	bool level3selected = false;
	bool ispaused = false;
	bool isgameover = false;
	float scoremultiplier = 0.01f;
	int score = 0;
	int scoreLevel3 = 0;


//You won_________________

	Texture bg;
	if (!bg.loadFromFile("pic/showup/bg.jpg"))
	{
		cout << "Layer1 not loaded" << endl;
		return EXIT_FAILURE;
	}
	Sprite bg1;
	bg1.setTexture(bg);
	bg1.setScale((float)window.getSize().x / bg.getSize().x, (float)window.getSize().y / bg.getSize().y);
	bg1.setPosition(0, 0);
//____________________________
// 
//------------------------------------------------------------Level 1 -----------------------------------------------------------
		//Texture 1

	Texture l1_level1;
	if (!l1_level1.loadFromFile("pic/level1/L1.png"))
	{
		cout << "Layer1 not loaded" << endl;
		return EXIT_FAILURE;
	}
	Sprite layer1_level1;
	layer1_level1.setTexture(l1_level1);
	layer1_level1.setScale((float)window.getSize().x / l1_level1.getSize().x, (float)window.getSize().y / l1_level1.getSize().y);
	layer1_level1.setPosition(0, 0);
	//copy
	Sprite layer1Copy_level1;
	layer1Copy_level1.setTexture(l1_level1);
	layer1Copy_level1.setScale((float)window.getSize().x / l1_level1.getSize().x, (float)window.getSize().y / l1_level1.getSize().y);
	layer1Copy_level1.setPosition((float)window.getSize().x, 0);
	
	//Texture 2
	Texture l2_level1;
	if (!l2_level1.loadFromFile("pic/level1/L2.png"))
	{
		cout << "Layer2 not loaded" << endl;
		return EXIT_FAILURE;
	}
	Texture l2Copy_level1;
	if (!l2Copy_level1.loadFromFile("pic/level1/L2C.png"))
	{
		cout << "File layer2 copy not loaded" << endl;
		//	return EXIT_FAILURE;
	}
	Sprite layer2_level1;
	layer2_level1.setTexture(l2_level1);
	layer2_level1.setScale((float)window.getSize().x / l2_level1.getSize().x, (float)window.getSize().y / l2_level1.getSize().y);
	layer2_level1.setPosition(0, 0);
	//copy
	Sprite layer2Copy_level1;
	layer2Copy_level1.setTexture(l2Copy_level1);
	layer2Copy_level1.setScale((float)window.getSize().x / l2Copy_level1.getSize().x, (float)window.getSize().y / l2Copy_level1.getSize().y);
	layer2Copy_level1.setPosition((float)window.getSize().x, 0);
	
	//Texture 3
	Texture l3_level1;
	if (!l3_level1.loadFromFile("pic/level1/L3.png"))
	{
		cout << "Layer3 not loaded" << endl;
		//	return EXIT_FAILURE;
	}
	Sprite layer3_level1;
	layer3_level1.setTexture(l3_level1);
	layer3_level1.setScale((float)window.getSize().x / l3_level1.getSize().x, (float)window.getSize().y / l3_level1.getSize().y);
	layer3_level1.setPosition(0, 0);
	//copy
	Sprite layer3Copy_level1;
	layer3Copy_level1.setTexture(l3_level1);
	layer3Copy_level1.setScale((float)window.getSize().x / l3_level1.getSize().x, (float)window.getSize().y / l3_level1.getSize().y);
	layer3Copy_level1.setPosition((float)window.getSize().x, 0);
	
	//Texture 4
	Texture l4_level1;
	if (!l4_level1.loadFromFile("pic/level1/L4.png"))
	{
		cout << "Layer4 not loaded" << endl;
		return EXIT_FAILURE;
	}
	Sprite layer4_level1;
	layer4_level1.setTexture(l4_level1);
	layer4_level1.setScale((float)window.getSize().x / l4_level1.getSize().x, (float)window.getSize().y / l4_level1.getSize().y);
	layer4_level1.setPosition(0, 0);
	//copy
	Sprite layer4Copy_level1;
	layer4Copy_level1.setTexture(l4_level1);
	layer4Copy_level1.setScale((float)window.getSize().x / l4_level1.getSize().x, (float)window.getSize().y / l4_level1.getSize().y);
	layer4Copy_level1.setPosition((float)window.getSize().x, 0);
	
	//Texture 5
	Texture l5_level1;
	if (!l5_level1.loadFromFile("pic/level1/L5.png"))
	{
		cout << "Layer5 not loaded" << endl;
		return EXIT_FAILURE;
	}
	Sprite layer5_level1;
	layer5_level1.setTexture(l5_level1);
	layer5_level1.setScale((float)window.getSize().x / l5_level1.getSize().x, (float)window.getSize().y / l5_level1.getSize().y);
	layer5_level1.setPosition(0, 0);
	//copy
	Sprite layer5Copy_level1;
	layer5Copy_level1.setTexture(l5_level1);
	layer5Copy_level1.setScale((float)window.getSize().x / l5_level1.getSize().x, (float)window.getSize().y / l5_level1.getSize().y);
	layer5Copy_level1.setPosition((float)window.getSize().x, 0);

	//layer speed
	float l1speed_level1 = 0.5f;
	float l2speed_level1 = 1.0f;
	float l3speed_level1 = 2.5f;
	float l4speed_level1 = 2.5f;
	float l5speed_level1 = 6.0f;

	//Character
	Texture player_level1;
	if (!player_level1.loadFromFile("pic/level1/sprite.png"))
	{
		cout << "PLayer not Loaded!" << endl;
		return EXIT_FAILURE;
	}
	Sprite spritePlayer_level1;
	spritePlayer_level1.setTexture(player_level1);
	spritePlayer_level1.setScale(0.35, 0.35);
	spritePlayer_level1.setPosition(300, 678);
	int currentFrame_level1 = 0;
	int row_level1 = 0;
	Clock clock_level1;
	double frameTime_level1 = 0.07f;
	double timeCalculator_level1 = 0;
	Time elapsedTime_level1;
	IntRect arrayOfFrames_level1[2][5] =
	{
		{
			IntRect(47, 50, 227, 333),
			IntRect(297, 78, 233, 333),
			IntRect(566, 98, 240, 333),
			IntRect(862, 81, 227, 333),
			IntRect(1147, 96, 287, 284),
		},
		{
			IntRect(47, 421, 204, 298),
			IntRect(297, 423, 233, 298),
			IntRect(566, 437, 240, 298),
			IntRect(862, 428, 213, 298),
			IntRect(1147, 422, 206, 298),
		}
	};
	//jumping
	float jumpVelocity_level1 = -650.0f;
	float gravity_level1 = 1000.0f;
	bool isJumping_level1 = false;
	//obstacles
	float obstacleSpeed_level1 = 355;
	vector<Texture> obstacleTextures_level1;
	for (int i = 0; i < 4; ++i) {
		Texture texture_level1;
		if (texture_level1.loadFromFile("pic/level1/obstacle_level1" + to_string(i + 1) + ".png")) {
			obstacleTextures_level1.push_back(texture_level1);
		}
		else {
			cout << "Failed to load obstacle" << i + 1 << " texture!" << endl;
		}
	}
	vector<Obstacle_level1> obstacles_level1;
	srand(static_cast<unsigned>(time(nullptr))); // Seed the random number generator
	//Making time spawn for displaying obstacle
	Clock obstacleSpawnClock_level1;
	Time obstacleSpawnInterval_level1 = seconds(3.0);


	//------------------------------------------------------End of level 1 ----------------------------------------------------------


	//------------------------------------------------------------Level 2 -----------------------------------------------------------

	//Texture 1
	Texture level2_1bg;
	if (!level2_1bg.loadFromFile("pic/Level2/L1.jpg"))
	{
		cout << "Layer1 not loaded" << endl;
		return EXIT_FAILURE;
	}
	Texture level2_new;
	if (!level2_new.loadFromFile("pic/Level2/L1.jpg"))
	{
		cout << "Layer1 not loaded" << endl;
		return EXIT_FAILURE;
	}
	Sprite level2new;
	level2new.setTexture(level2_new);
	level2new.setScale((float)window.getSize().x / level2_new.getSize().x, (float)window.getSize().y / level2_new.getSize().y);
	level2new.setPosition(0, 0);

	Sprite layer1_level2;
	layer1_level2.setTexture(level2_1bg);
	layer1_level2.setScale((float)window.getSize().x / level2_1bg.getSize().x, (float)window.getSize().y / level2_1bg.getSize().y);
	layer1_level2.setPosition(0, 0);
	//copy
	Sprite layer1_level2Copy;
	layer1_level2Copy.setTexture(level2_1bg);
	layer1_level2Copy.setScale((float)window.getSize().x / level2_1bg.getSize().x, (float)window.getSize().y / level2_1bg.getSize().y);
	layer1_level2.setPosition((float)window.getSize().x, 0);
	float l1speed_level2 = 7.0f;

	//Character
	Texture player_level2;
	if (!player_level2.loadFromFile("pic/level2/sprite.png"))
	{
		cout << "player not loaded" << endl;
		return EXIT_FAILURE;
	}
	Sprite spritePlayer_level2;
	spritePlayer_level2.setTexture(player_level2);
	spritePlayer_level2.setScale(0.35, 0.35);
	spritePlayer_level2.setPosition(300, 635);
	int currentFrame_level2 = 0;
	int row_level2 = 0;
	Clock clock_level2;
	double frameTime_level2 = 0.07f;
	double timeCalculator_level2 = 0;
	Time elapsedTime_level2;
	IntRect arrayOfFrames_level2[2][5] =
	{
		{
			IntRect(47, 50, 227, 333),
			IntRect(297, 78, 233, 333),
			IntRect(566, 98, 240, 333),
			IntRect(862, 81, 227, 333),
			IntRect(1147, 96, 287, 284),
		},
		{
			IntRect(47, 421, 204, 298),
			IntRect(297, 423, 233, 298),
			IntRect(566, 437, 240, 298),
			IntRect(862, 428, 213, 298),
			IntRect(1147, 422, 206, 298),
		}
	};
	//jumping
	float jumpVelocity_level2 = -650.0f;
	float gravity_level2 = 1000.0f;
	bool isJumping_level2 = false;
	float obstacleSpeed_level2 = 417.0f;
	vector<Texture> obstacleTextures_level2;
	for (int i = 0; i < 4; ++i) {
		Texture texture_level2;
		if (texture_level2.loadFromFile("pic/level2/obstacle_level2" + to_string(i + 1) + ".png")) {
			obstacleTextures_level2.push_back(texture_level2);
		}
		else {
			cout << "Failed to load obstacle" << i + 1 << " texture!" << endl;
		}
	}
	vector<Obstacle_level2> obstacles_level2;
	srand(static_cast<unsigned>(time(nullptr))); // Seed the random number generator

	Clock obstacleSpawnClock_level2;
	Time obstacleSpawnInterval_level2 = seconds(2.6);

	//------------------------------------------------------End of level 2 ----------------------------------------------------------
	//------------------------------------------------------------Level 3 -----------------------------------------------------------

	//image to put in background of main moving background
	Texture nnew;
	if (!nnew.loadFromFile("pic/level3/new.png"))
	{
		cout << "Layer1 not loaded" << endl;
		return EXIT_FAILURE;
	}
	Sprite nnew1;
	nnew1.setTexture(nnew);
	nnew1.setScale((float)window.getSize().x / nnew.getSize().x, (float)window.getSize().y / nnew.getSize().y);
	nnew1.setPosition(0, 0);

	//Texture 1

	Texture l1_level3;
	if (!l1_level3.loadFromFile("pic/level3/1.png"))
	{
		cout << "Layer1 not loaded" << endl;
		return EXIT_FAILURE;
	}
	Sprite layer1_level3;
	layer1_level3.setTexture(l1_level3);
	layer1_level3.setScale((float)window.getSize().x / l1_level3.getSize().x, (float)window.getSize().y / l1_level3.getSize().y);
	layer1_level3.setPosition(0, 0);
	//copy
	Sprite layer1Copy_level3;
	layer1Copy_level3.setTexture(l1_level3);
	layer1Copy_level3.setScale((float)window.getSize().x / l1_level3.getSize().x, (float)window.getSize().y / l1_level3.getSize().y);
	layer1Copy_level3.setPosition(0, -900);
	//Texture 2

	Texture l2_level3;
	if (!l2_level3.loadFromFile("pic/level3/2.png"))
	{
		cout << "Layer2 not loaded" << endl;
		return EXIT_FAILURE;
	}
	Texture l2Copy_level3;
	if (!l2Copy_level3.loadFromFile("pic/level3/2.png"))
	{
		cout << "File layer2 copy not loaded" << endl;
		//	return EXIT_FAILURE;
	}
	Sprite layer2_level3;
	layer2_level3.setTexture(l2_level3);
	layer2_level3.setScale((float)window.getSize().x / l2_level3.getSize().x, (float)window.getSize().y / l2_level3.getSize().y);
	layer2_level3.setPosition(0, 0);
	//copy
	Sprite layer2Copy_level3;
	layer2Copy_level3.setTexture(l2Copy_level3);
	layer2Copy_level3.setScale((float)window.getSize().x / l2Copy_level3.getSize().x, (float)window.getSize().y / l2Copy_level3.getSize().y);
	layer2Copy_level3.setPosition((float)window.getSize().x, 0);
	
	//Texture 3
	Texture l3_level3;
	if (!l3_level3.loadFromFile("pic/level3/3.png"))
	{
		cout << "Layer3 not loaded" << endl;
		//	return EXIT_FAILURE;
	}
	Sprite layer3_level3;
	layer3_level3.setTexture(l3_level3);
	layer3_level3.setScale((float)window.getSize().x / l3_level3.getSize().x, (float)window.getSize().y / l3_level3.getSize().y);
	layer3_level3.setPosition(0, 0);
	//copy
	Sprite layer3Copy_level3;
	layer3Copy_level3.setTexture(l3_level3);
	layer3Copy_level3.setScale((float)window.getSize().x / l3_level3.getSize().x, (float)window.getSize().y / l3_level3.getSize().y);
	layer3Copy_level3.setPosition((float)window.getSize().x, 0);
	
	//Texture 4
	Texture l4_level3;
	if (!l4_level3.loadFromFile("pic/level3/4.png"))
	{
		cout << "Layer4 not loaded" << endl;
		return EXIT_FAILURE;
	}
	Sprite layer4_level3;
	layer4_level3.setTexture(l4_level3);
	layer4_level3.setScale((float)window.getSize().x / l4_level3.getSize().x, (float)window.getSize().y / l4_level3.getSize().y);
	layer4_level3.setPosition(0, 0);
	//copy
	Sprite layer4Copy_level3;
	layer4Copy_level3.setTexture(l4_level3);
	layer4Copy_level3.setScale((float)window.getSize().x / l4_level3.getSize().x, (float)window.getSize().y / l4_level3.getSize().y);
	layer4Copy_level3.setPosition((float)window.getSize().x, 0);
	
	//Texture 5
	Texture l5_level3;
	if (!l5_level3.loadFromFile("pic/level3/5.png"))
	{
		cout << "Layer5 not loaded" << endl;
		return EXIT_FAILURE;
	}
	Sprite layer5_level3;
	layer5_level3.setTexture(l5_level3);
	layer5_level3.setScale((float)window.getSize().x / l5_level3.getSize().x, (float)window.getSize().y / l5_level3.getSize().y);
	layer5_level3.setPosition(0, 0);
	//copy
	Sprite layer5Copy_level3;
	layer5Copy_level3.setTexture(l5_level3);
	layer5Copy_level3.setScale((float)window.getSize().x / l5_level3.getSize().x, (float)window.getSize().y / l5_level3.getSize().y);
	layer5Copy_level3.setPosition((float)window.getSize().x, 0);

	//Character
	Texture player_level3;
	if (!player_level3.loadFromFile("pic/level3/sprite.png"))
	{
		cout << "PLayer not Loaded!" << endl;
		return EXIT_FAILURE;
	}
	Sprite spritePlayer_level3;
	spritePlayer_level3.setTexture(player_level3);
	spritePlayer_level3.setScale(0.35, 0.35);
	spritePlayer_level3.setPosition(300, 740);
	int currentFrame_level3 = 0;
	int row_level3 = 0;
	Clock clock_level3;
	double frameTime_level3 = 0.07f;
	double timeCalculator_level3 = 0;
	Time elapsedTime_level3;
	IntRect arrayOfFrames_level3[2][5] =
	{
		{
			IntRect(47, 50, 227, 333),
			IntRect(297, 78, 233, 333),
			IntRect(566, 98, 240, 333),
			IntRect(862, 81, 227, 333),
			IntRect(1147, 96, 287, 284),
		},
		{
			IntRect(47, 421, 204, 298),
			IntRect(297, 423, 233, 298),
			IntRect(566, 437, 240, 298),
			IntRect(862, 428, 213, 298),
			IntRect(1147, 422, 206, 298),
		}
	};
	bool youwon = false;

	//jumping
	float jumpVelocity_level3 = -660.0f;
	float gravity_level3 = 1100.0f;
	bool isJumping_level3 = false;
	//obstacles
	float obstacleSpeed_level3 = 485.0f;
	vector<Texture> obstacleTextures_level3;
	for (int i = 0; i < 4; ++i) {
		Texture texture_level3;
		if (texture_level3.loadFromFile("pic/level3/obstacle_level3" + to_string(i + 1) + ".png")) {
			obstacleTextures_level3.push_back(texture_level3);
		}
		else {
			cout << "Failed to load obstacle" << i + 1 << " texture!" << endl;
		}
	}
	vector<Obstacle_level3> obstacles_level3;
	srand(static_cast<unsigned>(time(nullptr))); // Seed the random number generator

	Clock obstacleSpawnClock_level3;
	Time obstacleSpawnInterval_level3 = seconds(2.6);

	//layer speed
	float l1speed_level3 = 1.5f;
	float l2speed_level3 = 8.0f;
	float l3speed_level3 = 2.5f;
	float l4speed_level3 = 2.0f;
	float l5speed_level3 = 1.0f;
	//------------------------------------------------------End of level 3 ----------------------------------------------------------
	music4.play();
	Clock newclock;
	while (window.isOpen())
	{
		music4.setLoop(true);
//------------------------------------------------------------Level 1 -----------------------------------------------------------
		elapsedTime_level1 = clock_level1.restart();

//------------------------------------------------------End of level 1 ----------------------------------------------------------

//------------------------------------------------------------Level 2 -----------------------------------------------------------

		elapsedTime_level2 = clock_level2.restart();
//------------------------------------------------------End of level 2 ----------------------------------------------------------
//------------------------------------------------------------Level 3 -----------------------------------------------------------
		elapsedTime_level3 = clock_level3.restart();
//------------------------------------------------------End of level 3 ----------------------------------------------------------
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
//------------------------------------------------------------Level 1 -----------------------------------------------------------
			if ((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space ||
				event.key.code == sf::Keyboard::W ||
				event.key.code == sf::Keyboard::Up) && !isJumping_level1)
			{
				isJumping_level1 = true;
			}
			else if (event.type == Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
				{
					ispaused = true;
					obstaclespawn_level1 = true;
					music1.pause();
					music4.play();
				}
			}
			if (level1selected == true)
			{
				if (event.type == Event::MouseButtonReleased)
				{
					Vector2i mouseposition = Mouse::getPosition(window);
					if (restart.getGlobalBounds().contains(static_cast<Vector2f>(mouseposition)))
					{
						isgameover = false;
						obstacles_level1.clear();
						music1.setPlayingOffset(seconds(77.f));
						music4.pause();
						music1.play();
						scoremultiplier = 0.01f;
						score = 0;
					}
				}
			}
//------------------------------------------------------End of level 1 ----------------------------------------------------------
//------------------------------------------------------------Level 2 -----------------------------------------------------------

			if ((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space ||
				event.key.code == sf::Keyboard::W ||
				event.key.code == sf::Keyboard::Up) && !isJumping_level2) {
				isJumping_level2 = true;
			}
			if ((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space ||
				event.key.code == sf::Keyboard::W ||
				event.key.code == sf::Keyboard::Up) && !isJumping_level1)
			{
				isJumping_level1 = true;
			}
			else if (event.type == Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
				{

					ispaused = true;
					obstaclespawn_level2 = true;
					music2.pause();
					music4.play();
				}
			}
			if (level2selected == true)
			{
				if (event.type == Event::MouseButtonReleased)
				{
					Vector2i mouseposition = Mouse::getPosition(window);
					if (restart.getGlobalBounds().contains(static_cast<Vector2f>(mouseposition)))
					{
						isgameover = false;
						obstacles_level2.clear();
						music2.setPlayingOffset(seconds(99.f));
						music4.pause();
						music2.play();
						scoremultiplier = 0.01f;
						score = 0;
					}
				}
			}
//------------------------------------------------------End of level 2 ----------------------------------------------------------
//------------------------------------------------------------Level 3 -----------------------------------------------------------
			if ((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space ||
				event.key.code == sf::Keyboard::W ||
				event.key.code == sf::Keyboard::Up) && !isJumping_level3) {
				isJumping_level3 = true;
			}
			if ((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space ||
				event.key.code == sf::Keyboard::W ||
				event.key.code == sf::Keyboard::Up) && !isJumping_level1)
			{
				isJumping_level1 = true;
			}
			else if (event.type == Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
				{

					ispaused = true;
					obstaclespawn_level3 = true;
					music3.pause();
					music4.play();
				}
			}
			if (level3selected == true)
			{
				if (event.type == Event::MouseButtonReleased)
				{
					Vector2i mouseposition = Mouse::getPosition(window);
					if (restart.getGlobalBounds().contains(static_cast<Vector2f>(mouseposition)))
					{
						isgameover = false;
						obstacles_level3.clear();
						music3.setPlayingOffset(seconds(106.f));
						music4.pause();
						music3.play();
						scoremultiplier = 0.01f;
						score = 0;
					}
					if (resumeText.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
					{
						ispaused = false;
						inLevelSelection = false;
						obstaclespawn_level3 = false;
					}
					if (back1Text.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
					{
						youwon = false;
						inMainMenu = true;
						inLevelSelection = false;
						level1selected = false;
						level2selected = false;
						level3selected = false;
						ispaused = false;
						score = 0;
						obstaclespawn_level3 = false;
					}
					if (quit1.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
					{
						window.close();
					}
				}
			}
//------------------------------------------------------End of level 3 ----------------------------------------------------------
			else if (event.type == Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == Mouse::Left)
				{
					// Check if the mouse is over the "Start" text
					if (startText.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
					{
						inMainMenu = false;
						inLevelSelection = true;
					}
					// Check if the mouse is over the "Quit" text
					else if (quitText.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
					{
						window.close();
					}
					
					else if (quit1.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
					{
						window.close();
					}
					//Level 1 Text
					else if (level1Text.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
					{
						youwon = false;
						level1selected = true;
						inLevelSelection = false;
						music1.setLoop(true);
						music4.pause();
						music1.play();
					}
					//Level 2 Text
					else if (level2Text.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
					{
						youwon = false;
						level2selected = true;
						inLevelSelection = false;
						music2.setLoop(true);
						music2.play();
					}
					//Level 3 Text
					else if (level3Text.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
					{
						youwon = false;
						level3selected = true;
						inLevelSelection = false;
						music3.setLoop(true);
						music4.pause();
						music3.play();
					}
					//Resume Text
					else if (resumeText.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
					{
						ispaused = false;
						obstaclespawn_level1 = false;
						obstaclespawn_level2 = false;
						inLevelSelection = false;
						if (level1selected)
						{
							music4.pause();
							music1.play();
						}
						else if (level2selected)
						{
							music4.pause();
							music2.play();
						}
						else if (level3selected)
						{
							music4.pause();
							music3.play();
						}
					}
					//Back Text
					else if (back1Text.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
					{

						inMainMenu = true;
						inLevelSelection = false;
						level1selected = false;
						level2selected = false;
						level3selected = false;
						ispaused = false;
						score = 0;
						scoreLevel3 = 0;
						obstaclespawn_level1 = false;
						obstaclespawn_level2 = false;
						obstaclespawn_level3 = false;

					}
					//Back Text
					else if (returnText.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
					{
						inMainMenu = true;
						inLevelSelection = false;
					}
//You won___________________
					//Next Level Text
					else if (nextLevelText.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
					{
						youwon = false;
						score = 0;
						inLevelSelection = true;
						level1selected = false;
						level2selected = false;
						level3selected = false;
					}
//_______________________________
				}
			}
		}

		//Background Movement
		//layer1 
		layer1_showup.move(-layer1_showup_speed, 0);
		// Reset sprites when they go off the screen
		if (layer1_showup.getPosition().x <= (float)(-1500)) {
			layer1_showup.setPosition((float)window.getSize().x, 0);
		}
		//layer 1 copy 
		layer1_showup_copy.move(-layer1_showup_speed, 0);
		if (layer1_showup_copy.getPosition().x <= (float)(-1500)) {
			layer1_showup_copy.setPosition((float)window.getSize().x, 0);
		}
		//layer 2 
		layer2_showup.move(-layer2_showup_speed, 0);
		if (layer2_showup.getPosition().x <= (float)(-1500)) {
			layer2_showup.setPosition((float)window.getSize().x, 0);
		}
		//layer 2 copy
		layer2_showup_copy.move(-layer2_showup_speed, 0);
		if (layer2_showup_copy.getPosition().x <= (float)(-1500)) {
			layer2_showup_copy.setPosition((float)window.getSize().x, 0);
		}
		//layer 3 
		layer3_showup.move(-layer3_showup_speed, 0);
		if (layer3_showup.getPosition().x <= (float)(-1500)) {
			layer3_showup.setPosition((float)window.getSize().x, 0);
		}
		//layer 3 
		layer3_showup_copy.move(-layer3_showup_speed, 0);
		if (layer3_showup_copy.getPosition().x <= (float)(-1500)) {
			layer3_showup_copy.setPosition((float)window.getSize().x, 0);
		}
		window.clear();
		window.draw(layer1_showup);
		window.draw(layer1_showup_copy);
		window.draw(layer2_showup);
		window.draw(layer2_showup_copy);
		window.draw(layer3_showup);
		window.draw(layer3_showup_copy);
		window.draw(logoSprite);
		
		if (inMainMenu)
		{
			logoSprite.setPosition((window.getSize().x / 2), (window.getSize().y / 2) - 150);
			window.draw(startText);
			window.draw(quitText);
		}
		else if (inLevelSelection)
		{
			logoSprite.setPosition((window.getSize().x / 2) - 290, (window.getSize().y / 2));
			youwon = false;
			window.draw(level1Text);
			window.draw(level2Text);
			window.draw(level3Text);
			window.draw(quit2Text);
			window.draw(returnText);
			window.draw(noteText);
			window.draw(note1Text);
		}
		else if (ispaused)
		{
			window.draw(layer1_showup);
			window.draw(layer1_showup_copy);
			window.draw(layer2_showup);
			window.draw(layer2_showup_copy);
			window.draw(layer3_showup);
			window.draw(layer3_showup_copy);
			window.draw(pause);
			window.draw(resumeText);
			window.draw(back1Text);
			window.draw(quit1);
		}
		else if (isgameover == true)
		{
			music1.pause();
			music2.pause();
			music3.pause();
			window.draw(layer1_showup);
			window.draw(layer1_showup_copy);
			window.draw(layer2_showup);
			window.draw(layer2_showup_copy);
			window.draw(layer3_showup);
			window.draw(layer3_showup_copy);
			window.draw(gameover);
			window.draw(restart);
		}
//you won__________level finish and displaying won screen
		if (level1selected) 
			{
			if (score > 3000)
			{
				youwon = true;
				level1selected = false;
				score = 0;
			}
		}
		if (level2selected)
		{
			if (score > 6000)
			{
				youwon = true;
				level2selected = false;
				score = 0;
			}
		}

		if (youwon)
		{
			music4.play();
			music1.pause();
			music2.pause();
			music3.pause();
			window.draw(bg1);
			window.draw(wonText);
			window.draw(nextLevelText);
			inMainMenu = false;
			inLevelSelection = false;
			level1selected = false;
		}
//__________________________
		
//------------------------------------------------------------Level 1 -----------------------------------------------------------
		if (level1selected)
		{
			if (!ispaused && isgameover == false)
			{
				scoretext.setString("score:" + to_string(score));

				//Background Movement
				//layer1 originol
				layer1_level1.move(-l1speed_level1, 0);
				// Reset sprites when they go off the screen
				if (layer1_level1.getPosition().x <= (float)(-1500)) {
					layer1_level1.setPosition((float)window.getSize().x, 0);
				}
				//layer 1 copy
				layer1Copy_level1.move(-l1speed_level1, 0);
				if (layer1Copy_level1.getPosition().x <= (float)(-1500)) {
					layer1Copy_level1.setPosition((float)window.getSize().x, 0);
				}
				//layer2 originol
				layer2_level1.move(-l2speed_level1, 0);
				if (layer2_level1.getPosition().x <= (float)(-1500)) {
					layer2_level1.setPosition((float)window.getSize().x, 0);
				}
				//layer 2 copy
				layer2Copy_level1.move(-l2speed_level1, 0);
				if (layer2Copy_level1.getPosition().x <= (float)(-1500)) {
					layer2Copy_level1.setPosition((float)window.getSize().x, 0);
				}

				//layer3 originol
				layer3_level1.move(-l3speed_level1, 0);
				if (layer3_level1.getPosition().x <= (float)(-1500)) {
					layer3_level1.setPosition((float)window.getSize().x, 0);
				}
				//layer 3 copy
				layer3Copy_level1.move(-l3speed_level1, 0);
				if (layer3Copy_level1.getPosition().x <= (float)(-1500)) {
					layer3Copy_level1.setPosition((float)window.getSize().x, 0);
				}
				//layer4 originol
				layer4_level1.move(-l4speed_level1, 0);
				if (layer4_level1.getPosition().x <= (float)(-1500)) {
					layer4_level1.setPosition((float)window.getSize().x, 0);
				}
				//layer 4 copy
				layer4Copy_level1.move(-l4speed_level1, 0);
				if (layer4Copy_level1.getPosition().x <= (float)(-1500)) {
					layer4Copy_level1.setPosition((float)window.getSize().x, 0);
				}
				//layer5 originol
				layer5_level1.move(-l5speed_level1, 0);
				if (layer5_level1.getPosition().x <= (float)(-1500)) {
					layer5_level1.setPosition((float)window.getSize().x, 0);
				}
				//layer 5 copy
				layer5Copy_level1.move(-l5speed_level1, 0);
				if (layer5Copy_level1.getPosition().x <= (float)(-1500)) {
					layer5Copy_level1.setPosition((float)window.getSize().x, 0);
				}
				// Spawning obstacles
				if (!obstaclespawn_level1 && obstacleSpawnClock_level1.getElapsedTime() >= obstacleSpawnInterval_level1) {
					int randomObstacleType_level1 = rand() % obstacleTextures_level1.size();
					Obstacle_level1 newObstacle_level1(obstacleTextures_level1[randomObstacleType_level1], Vector2f(1500, 688), obstacleSpeed_level1); // Adjust speed as needed
					obstacles_level1.push_back(newObstacle_level1);

					obstacleSpawnClock_level1.restart();
				}
				// Check and update obstacle positions
				for (size_t i = 0; i < obstacles_level1.size(); ++i) {
					obstacles_level1[i].move_level1(elapsedTime_level1.asSeconds());

					// Remove obstacles that have moved off the screen
					if (obstacles_level1[i].sprite_level1.getPosition().x + obstacles_level1[i].sprite_level1.getGlobalBounds().width < 0) {
						obstacles_level1.erase(obstacles_level1.begin() + i);
						--i; // Adjust index to account for the removed obstacle
					}
				}
				// Check collision with obstacles
				for (const Obstacle_level1& obstacle : obstacles_level1) {

					FloatRect characterBounds_level1 = spritePlayer_level1.getGlobalBounds();
					FloatRect obstacleBounds_level1 = obstacle.sprite_level1.getGlobalBounds();

					// Adjust these conditions based on your specific requirements
					if (characterBounds_level1.intersects(obstacleBounds_level1) && characterBounds_level1.left < obstacleBounds_level1.top) {
						cout << "Collision with obstacle!" << endl;
						sound.play();
						obstacles_level1.clear();
						isgameover = true;
						score = 0;
						scoreLevel3 = 0;
						music4.play();
					}
				}
				//jumping
				if (isJumping_level1) {
					double jumpPosition = spritePlayer_level1.getPosition().y + (jumpVelocity_level1 * elapsedTime_level1.asSeconds());
					if (jumpPosition > 678) {
						jumpPosition = 678;
						isJumping_level1 = false;
					}
					spritePlayer_level1.setPosition(spritePlayer_level1.getPosition().x, jumpPosition);

					jumpVelocity_level1 += gravity_level1 * elapsedTime_level1.asSeconds();

					// If the character is back on the ground, reset the jump velocity
					if (spritePlayer_level1.getPosition().y == 678.0f) {
						jumpVelocity_level1 = -650.0f;
					}
				}
				//player
				timeCalculator_level1 += elapsedTime_level1.asSeconds();
				if (timeCalculator_level1 >= frameTime_level1)
				{
					currentFrame_level1 = (currentFrame_level1 + 1) % 5;
					timeCalculator_level1 = 0.f;
					if (currentFrame_level1 == 0) {
						row_level1 = (row_level1 + 1) % 2;
					}
					//increament the time based on the speed
					score += static_cast<int>(obstacleSpeed_level1 * scoremultiplier);

					//increament the score multiplier over time
					scoremultiplier += 0.00001f;

				}
				window.clear();
				window.draw(layer1_level1);
				window.draw(layer1Copy_level1);
				window.draw(layer2_level1);
				window.draw(layer2Copy_level1);
				window.draw(layer3_level1);
				window.draw(layer3Copy_level1);
				window.draw(layer4_level1);
				window.draw(layer4Copy_level1);
				spritePlayer_level1.setTextureRect(arrayOfFrames_level1[row_level1][currentFrame_level1]);
				for (const Obstacle_level1& obstacle : obstacles_level1) {
					window.draw(obstacle.sprite_level1);
				}
				//player
				spritePlayer_level1.setTextureRect(arrayOfFrames_level1[row_level1][currentFrame_level1]);
				window.draw(spritePlayer_level1);
				window.draw(layer5_level1);
				window.draw(layer5Copy_level1);
				window.draw(scoretext);
				
			
			}
		}
//------------------------------------------------------------ End of Level 1 -----------------------------------------------------------

//------------------------------------------------------------Level 2 -----------------------------------------------------------
		if (level2selected)
		{
			if (!ispaused && isgameover == false)
			{
				music4.pause();
				//Background Movement
				//layer1_level2 originol
				scoretext.setString("score:" + to_string(score));
				layer1_level2.move(-l1speed_level2, 0);
				// Reset sprites when they go off the screen
				if (layer1_level2.getPosition().x <= (float)(-1500)) {
					layer1_level2.setPosition((float)window.getSize().x, 0);
				}
				//layer 1 copy
				layer1_level2Copy.move(-l1speed_level2, 0);
				if (layer1_level2Copy.getPosition().x <= (float)(-1500)) {
					layer1_level2Copy.setPosition((float)window.getSize().x, 0);
				}
				// Spawning obstacles
				if (!obstaclespawn_level2 && obstacleSpawnClock_level2.getElapsedTime() >= obstacleSpawnInterval_level2) {
					int randomObstacleType_level2 = rand() % obstacleTextures_level2.size();
					Obstacle_level2 newObstacle(obstacleTextures_level2[randomObstacleType_level2], Vector2f(1500, 640), obstacleSpeed_level2); // Adjust speed as needed
					obstacles_level2.push_back(newObstacle);

					obstacleSpawnClock_level2.restart();
				}

				// Check and update obstacle positions
				for (size_t i = 0; i < obstacles_level2.size(); ++i) {
					obstacles_level2[i].move_level2(elapsedTime_level2.asSeconds());

					// Remove obstacles that have moved off the screen
					if (obstacles_level2[i].sprite_level2.getPosition().x + obstacles_level2[i].sprite_level2.getGlobalBounds().width < 0) {
						obstacles_level2.erase(obstacles_level2.begin() + i);
						--i; // Adjust index to account for the removed obstacle
					}
				}
				// Check collision with obstacles
				for (const Obstacle_level2& obstacle : obstacles_level2) {

					FloatRect characterBounds_level2 = spritePlayer_level2.getGlobalBounds();
					FloatRect obstacleBounds_level2 = obstacle.sprite_level2.getGlobalBounds();

					// Adjust these conditions based on your specific requirements
					if (characterBounds_level2.intersects(obstacleBounds_level2) && characterBounds_level2.left <= obstacleBounds_level2.top) {
						cout << "Collision with obstacle!" << endl;
						sound.play();
						obstacles_level2.clear();
						isgameover = true;
						music4.play();
					}
				}
				//jumping
				if (isJumping_level2) {
					double jumpPosition_level2 = spritePlayer_level2.getPosition().y + (jumpVelocity_level2 * elapsedTime_level2.asSeconds());
					if (jumpPosition_level2 > 635) { // Adjust the ground level
						jumpPosition_level2 = 635; // Reset the Y position
						isJumping_level2 = false;
					}
					spritePlayer_level2.setPosition(spritePlayer_level2.getPosition().x, jumpPosition_level2);

					jumpVelocity_level2 += gravity_level2 * elapsedTime_level2.asSeconds();
					// If the character is back on the ground, reset the jump velocity
					if (spritePlayer_level2.getPosition().y == 635.0f) { 
						jumpVelocity_level2 = -650.0f;
					}
				}
				//player
				timeCalculator_level2 += elapsedTime_level2.asSeconds();
				if (timeCalculator_level2 >= frameTime_level2)
				{
					currentFrame_level2 = (currentFrame_level2 + 1) % 5;
					timeCalculator_level2 = 0.f;
					if (currentFrame_level2 == 0) {
						row_level2 = (row_level2 + 1) % 2;
					}

					//increament the time based on the speed
					score += static_cast<int>(obstacleSpeed_level1 * scoremultiplier);
					//increament the score multiplier over time
					scoremultiplier += 0.0001f;
				}
				window.clear();
				window.draw(level2new);
				window.draw(layer1_level2);
				window.draw(layer1_level2Copy);

				//player
				spritePlayer_level2.setTextureRect(arrayOfFrames_level2[row_level2][currentFrame_level2]);
				for (const Obstacle_level2& obstacle : obstacles_level2) {
					window.draw(obstacle.sprite_level2);
				}
				window.draw(spritePlayer_level2);
				window.draw(scoretext);
			}
		}
//------------------------------------------------------End of level 2 ----------------------------------------------------------
//------------------------------------------------------------Level 3 -----------------------------------------------------------

		if (level3selected)
		{
			if (!ispaused && isgameover == false)
			{
				scoreLevel3Text.setString("Score:" + to_string(scoreLevel3));
				in.open("scoreLevel3.txt");
				in >> highscore;
				in.close();
				highScoreText.setString("High Score:"+ to_string(highscore));
				if (scoreLevel3 > highscore)
				{
					highscore = scoreLevel3;
					out.open("scoreLevel3.txt");
					out << highscore;
				}
				out.close();
				//Background Movement
				// layer1 original
				layer1_level3.move(0, l1speed_level3);
				// Reset sprites when they go off the screen
				if (layer1_level3.getPosition().y >= window.getSize().y) {
					layer1_level3.setPosition(0, -layer1_level3.getGlobalBounds().height);
				}
				// layer1 copy
				layer1Copy_level3.move(0, l1speed_level3);
				if (layer1Copy_level3.getPosition().y >= window.getSize().y) {
					layer1Copy_level3.setPosition(0, -layer1Copy_level3.getGlobalBounds().height);
				}
				//layer2 originol
				layer2_level3.move(-l2speed_level3, 0);
				if (layer2_level3.getPosition().x <= (float)(-1500)) {
					layer2_level3.setPosition((float)window.getSize().x, 0);
				}
				//layer 2 copy
				layer2Copy_level3.move(-l2speed_level3, 0);
				if (layer2Copy_level3.getPosition().x <= (float)(-1500)) {
					layer2Copy_level3.setPosition((float)window.getSize().x, 0);
				}
				//layer3 originol
				layer3_level3.move(-l3speed_level3, 0);
				if (layer3_level3.getPosition().x <= (float)(-1500)) {
					layer3_level3.setPosition((float)window.getSize().x, 0);
				}
				//layer 3 copy
				layer3Copy_level3.move(-l3speed_level3, 0);
				if (layer3Copy_level3.getPosition().x <= (float)(-1500)) {
					layer3Copy_level3.setPosition((float)window.getSize().x, 0);
				}
				//layer4 originol
				layer4_level3.move(-l4speed_level3, 0);
				if (layer4_level3.getPosition().x <= (float)(-1500)) {
					layer4_level3.setPosition((float)window.getSize().x, 0);
				}
				//layer 4 copy
				layer4Copy_level3.move(-l4speed_level3, 0);
				if (layer4Copy_level3.getPosition().x <= (float)(-1500)) {
					layer4Copy_level3.setPosition((float)window.getSize().x, 0);
				}
				//layer5 originol
				layer5_level3.move(-l5speed_level3, 0);
				if (layer5_level3.getPosition().x <= (float)(-1500)) {
					layer5_level3.setPosition((float)window.getSize().x, 0);
				}
				//layer 5 copy
				layer5Copy_level3.move(-l5speed_level3, 0);
				if (layer5Copy_level3.getPosition().x <= (float)(-1500)) {
					layer5Copy_level3.setPosition((float)window.getSize().x, 0);
				}
				//jumping
				if (isJumping_level3) {
					double jumpPosition = spritePlayer_level3.getPosition().y + (jumpVelocity_level3 * elapsedTime_level3.asSeconds());
					if (jumpPosition > 740) { 
						jumpPosition = 740;
						isJumping_level3 = false;
					}
					spritePlayer_level3.setPosition(spritePlayer_level3.getPosition().x, jumpPosition);
					jumpVelocity_level3 += gravity_level3 * elapsedTime_level3.asSeconds();
					// If the character is back on the ground, reset the jump velocity
					if (spritePlayer_level3.getPosition().y == 740.0f) {
						jumpVelocity_level3 = -660.0f;
					}
				}
				// Spawning obstacles
				if (!obstaclespawn_level3 && obstacleSpawnClock_level3.getElapsedTime() >= obstacleSpawnInterval_level3) {
					int randomObstacleType_level3 = rand() % obstacleTextures_level3.size();
					Obstacle_level3 newObstacle_level1(obstacleTextures_level3[randomObstacleType_level3], Vector2f(1500, 730), obstacleSpeed_level3); // Adjust speed as needed
					obstacles_level3.push_back(newObstacle_level1);
					obstacleSpawnClock_level3.restart();
				}

				// Check and update obstacle positions
				for (size_t i = 0; i < obstacles_level3.size(); ++i) {
					obstacles_level3[i].move_level3(elapsedTime_level3.asSeconds());
					// Remove obstacles that have moved off the screen
					if (obstacles_level3[i].sprite_level3.getPosition().x + obstacles_level3[i].sprite_level3.getGlobalBounds().width < 0) {
						obstacles_level3.erase(obstacles_level3.begin() + i);
						--i; // Adjust index to account for the removed obstacle
					}
				}
				// Check collision with obstacles
				for (const Obstacle_level3& obstacle : obstacles_level3) {
					FloatRect characterBounds_level3 = spritePlayer_level3.getGlobalBounds();
					FloatRect obstacleBounds_level3 = obstacle.sprite_level3.getGlobalBounds();

					// Adjust these conditions based on your specific requirements
					if (characterBounds_level3.intersects(obstacleBounds_level3) && characterBounds_level3.left < obstacleBounds_level3.top) {
						cout << "Collision with obstacle!" << endl;
						sound.play();
						obstacles_level3.clear();
						isgameover = true;
						scoreLevel3 = 0;
						music4.play();
					}
				}
				//player
				timeCalculator_level3 += elapsedTime_level3.asSeconds();
				if (timeCalculator_level3 >= frameTime_level3)
				{
					currentFrame_level3 = (currentFrame_level3 + 1) % 5;
					timeCalculator_level3 = 0.f;
					if (currentFrame_level3 == 0) {
						row_level3 = (row_level3 + 1) % 2;
					}
					//increament the time based on the speed
					scoreLevel3 += static_cast<int>(obstacleSpeed_level1 * scoremultiplier);
					//increament the score multiplier over time
					scoremultiplier += 0.00001f;
				}

				window.clear();
				window.draw(layer5_level3);
				window.draw(layer5Copy_level3);
				window.draw(layer4_level3);
				window.draw(layer4Copy_level3);
				window.draw(layer3_level3);
				window.draw(layer3Copy_level3);
				window.draw(nnew1);
				window.draw(layer2_level3);
				window.draw(layer2Copy_level3);
				//player
				spritePlayer_level3.setTextureRect(arrayOfFrames_level3[row_level3][currentFrame_level3]);
				//obstacle
				for (const Obstacle_level3& obstacle : obstacles_level3) {
					window.draw(obstacle.sprite_level3);
				}
				spritePlayer_level3.setTextureRect(arrayOfFrames_level3[row_level3][currentFrame_level3]);
				window.draw(spritePlayer_level3);
				window.draw(layer1_level3);
				window.draw(layer1Copy_level3);
				window.draw(scoreLevel3Text);
				window.draw(highScoreText);
				window.draw(highScoreText1);
			}
		}
		window.display();
	}
}