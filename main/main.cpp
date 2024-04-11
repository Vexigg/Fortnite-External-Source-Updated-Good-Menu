#include "includes/includes.hpp"
#include <iostream>
#include <vector>
#include <stdio.h>


#include <Windows.h>
#include <string>
#include "includes/utils.hpp"
#include <urlmon.h>
#include <tchar.h>

#include "general.h"
#include <random>

#include "flux.hpp"
#include "auth.hpp"


using namespace KeyAuth;


auto name = skCrypt("Temp"); // Application Name
auto ownerid = skCrypt("mo4lfTExuJ"); // Owner ID
auto secret = skCrypt("c85a64a968eec8cdeba7fdef5d281fd96dee018b7e1a4cd912cfc9c3651c3714"); // Application Secret
auto version = skCrypt("1.0"); // Application Version
auto url = skCrypt("https://keyauth.win/api/1.2/"); // change if you're self-hosting

api KeyAuthApp(name.decrypt(), ownerid.decrypt(), secret.decrypt(), version.decrypt(), url.decrypt()); // Dont touch this




std::string get_hwid() {
	DWORD volumeSerialNumber;

	if (!GetVolumeInformation("C:\\", NULL, 0, &volumeSerialNumber, NULL, NULL, NULL, 0)) {
		throw std::runtime_error("failed to get hwid");
	}

	std::string hwid = std::to_string(volumeSerialNumber);
	return hwid;
}


static std::time_t string_to_timet(std::string timestamp) {


	auto cv = strtol(timestamp.c_str(), NULL, 10); // long

	return (time_t)cv;
}

static std::tm timet_to_tm(time_t timestamp) {


	std::tm context;

	localtime_s(&context, &timestamp);

	return context;
}
const std::string compilation_date = (std::string)skCrypt(__DATE__);
const std::string compilation_time = (std::string)skCrypt(__TIME__);

std::string tm_to_readable_time2(tm ctx) {


	std::time_t now = std::time(nullptr);
	std::time_t expiry = std::mktime(&ctx);

	double remainingSeconds = std::difftime(expiry, now);

	if (remainingSeconds >= 60 * 60 * 24) {
		int remainingDays = static_cast<int>(remainingSeconds / (60 * 60 * 24));
		return std::to_string(remainingDays) + " day(s).";
	}
	else if (remainingSeconds >= 60 * 60) {
		int remainingHours = static_cast<int>(remainingSeconds / (60 * 60));
		return std::to_string(remainingHours) + " hour(s).";
	}
	else {
		int remainingMinutes = static_cast<int>(remainingSeconds / 60);
		return std::to_string(remainingMinutes) + " minute(s).";
	}
}

void DeleteKey(std::ifstream& File)
{

	std::string regfile("key.txt");
	std::ofstream(regfile, std::ios::trunc);
	File.setstate(std::ios::failbit);
	remove(regfile.c_str());
}

void sleepMilliseconds(int ms) {
	std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

std::string readFileIntoString(const std::string& path) {


	auto ss = std::ostringstream{};
	std::ifstream input_file(path);
	if (!input_file.is_open()) {
		std::cerr << E("Could Not Open License Key File") << std::endl;
		exit(EXIT_FAILURE);
	}
	ss << input_file.rdbuf();
	return ss.str();
}

HWND windowid = NULL;











void loadcheat() {
	
	system("cls");
	Sleep(200);
	Beep(500, 500);
	std::cout << (skCrypt("\n      Waiting For Fortnite")) << std::flush;

	while (windowid == NULL)
	{
		XorS(wind, "Fortnite  ");
		windowid = FindWindowA_Spoofed(0, wind.decrypt());
	}
	globals->hwnd = FindWindowA_Spoofed(NULL, "Fortnite  ");

	LI_FN(Sleep)(200);

	system("cls");

	std::cout << (skCrypt("\n      Found Fortnite")) << std::flush;

	LI_FN(Sleep)(1000);

	Beep(500, 500);
	HWND hwnd = GetConsoleWindow();
	if (hwnd != NULL) {

	}
	mem::find_process("FortniteClient-Win64-Shipping.exe");

	virtualaddy = mem::find_image();
	if (!virtualaddy)
	{
		std::cout << (skCrypt("Load Driver")) << std::flush;
	}

	globals->width = GetSystemMetrics_Spoofed(SM_CXSCREEN); globals->height = GetSystemMetrics_Spoofed(SM_CYSCREEN);

	if (Render->Setup() != RENDER_INFORMATION::RENDER_SETUP_SUCCESSFUL) ExitProcess(0);

	if (Hook->Setup() != HOOK_INFORMATION::HOOKS_SUCCESSFUL) ExitProcess(0);

	if (Game->Setup() != GAME_INFORMATION::GAME_SETUP_SUCCESSFUL) ExitProcess(0);

	Render->Render();
}



auto main() -> int
{
	int choice;



	mouse_interface();

	system("color 5");


	mem::find_driver();
	mouse_interface();
	KeyAuthApp.init();
	system("mode con cols=85 lines=17");

	//flux
	bool success = flux::set_application("clu1iyktn0001ns01lqmiyyxo");

	
	menu_:

	system("color 5");

	system("cls");
	printf(("            Welcome To Storm External   \n "));
	printf(("\n [1] Load Cheat\n [2] Load Driver\n > "));
	std::cin >> choice;
	switch (choice)
	{
	case 1:
		loadcheat();
	case 2:
		system(("cls"));
		system(("color 6"));
		//system(("curl https://files.offshore.cat/0mcyWYuv.sys --output C:\\Windows\\System32\\kernel.sys >nul 2>&1")); 
	//	system(("curl https://files.offshore.cat/G9GO25Ec.exe --output C:\\Windows\\System32\\mapper.exe >nul 2>&1")); 
		system(("C:\\Windows\\System32\\mapper.exe C:\\Windows\\System32\\kernel.sys"));
		std::remove(("C:\\Windows\\System32\\kernel.sys"));
		std::remove(("C:\\Windows\\System32\\mapper.exe"));
		system(("cls"));
		goto menu_;
	}
}

