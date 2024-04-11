
#include <D3DX11tex.h>
#include "fonts.h"
#include "images.h"
#include <vector>

enum RENDER_INFORMATION : int {
    RENDER_HIJACK_FAILED = 0,
    RENDER_IMGUI_FAILED = 1,
    RENDER_DRAW_FAILED = 2,
    RENDER_SETUP_SUCCESSFUL = 3
};




std::string ReadStringFromIni_Float(std::string file, std::string app, std::string key, int float_code)
{
    char buf[100];
    GetPrivateProfileStringA(app.c_str(), key.c_str(), _xor_("NULL").c_str(), buf, 100, file.c_str());

    if (float_code == 0)
    {
        system(_xor_("cls").c_str());
        std::cout << _xor_(" [").c_str() << _xor_("ERR - 14").c_str() << _xor_("] - Contact Support.").c_str();
        Sleep(5000);
        exit(0);
    }
    else if (float_code == 1) {

    }
    else if (float_code == 2) {

    }
    else if (float_code == 3) {

    }
    else if (float_code == 4) {
        globals->field_of_view = std::stof(buf);
    }
    else if (float_code == 5) {
        globals->smooth = std::stof(buf);
    }
    else if (float_code == 6) {
        globals->custom_delay = std::stof(buf);
    }
    else if (float_code == 7) {
        globals->maximum_distance = std::stof(buf);
    }
    else if (float_code == 8) {
        globals->aimbot_key = std::stof(buf);
    }
    else if (float_code == 9) {
        globals->triggerbot_key = std::stof(buf);
    }
    else if (float_code == 10) {
        rifle::aim_fov = std::stof(buf);
    }
    else if (float_code == 11) {
        rifle::smooth = std::stof(buf);
    }
    else if (float_code == 12) {
        shotgun::aim_fov = std::stof(buf);
    }
    else if (float_code == 13) {
        shotgun::smooth = std::stof(buf);
    }
    else if (float_code == 14) {
        smg::aim_fov = std::stof(buf);
    }
    else if (float_code == 15) {
        smg::smooth = std::stof(buf);
    }
    else if (float_code == 16) {
        sniper::aim_fov = std::stof(buf);
    }
    else if (float_code == 17) {
        sniper::smooth = std::stof(buf);
    }
    else if (float_code == 18) {
        globals->max_distance1 = std::stof(buf);
    }
    else if (float_code == 19) {
        globals->max_distance2 = std::stof(buf);
    }
    else if (float_code == 20) {
        globals->max_distance3 = std::stof(buf);
    }
    else if (float_code == 21) {
        globals->max_distance4 = std::stof(buf);
    }
    return (std::string)buf;
}



void WriteStringToIni(std::string string, std::string file, std::string app, std::string key)
{
    WritePrivateProfileStringA(app.c_str(), key.c_str(), string.c_str(), file.c_str());
}
std::string ReadStringFromIni(std::string file, std::string app, std::string key)
{
    char buf[100];
    GetPrivateProfileStringA(app.c_str(), key.c_str(), _xor_("NULL").c_str(), buf, 100, file.c_str());
    return (std::string)buf;
}

std::string FloatArrayToString(const float* array, int size) {
    std::ostringstream oss;
    for (int i = 0; i < size; ++i) {
        oss << array[i];
        if (i < size - 1) oss << ",";
    }
    return oss.str();
}


void SaveConfig()
{
    if (globals->aimbot)
        WriteStringToIni(_xor_("1").c_str(), _xor_("C:\\config").c_str(), _xor_("aimbot").c_str(), _xor_("aimbot").c_str());
    else
        WriteStringToIni(_xor_("0").c_str(), _xor_("C:\\config").c_str(), _xor_("aimbot").c_str(), _xor_("aimbot").c_str());
    if (globals->render_field_of_view)
        WriteStringToIni(_xor_("1").c_str(), _xor_("C:\\config").c_str(), _xor_("aimbot").c_str(), _xor_("drawfov").c_str());
    else
        WriteStringToIni(_xor_("0").c_str(), _xor_("C:\\config").c_str(), _xor_("aimbot").c_str(), _xor_("drawfov").c_str());
    if (globals->triggerbot)
        WriteStringToIni(_xor_("1").c_str(), _xor_("C:\\config").c_str(), _xor_("aimbot").c_str(), _xor_("triggerbot").c_str());
    else
        WriteStringToIni(_xor_("0").c_str(), _xor_("C:\\config").c_str(), _xor_("aimbot").c_str(), _xor_("triggerbot").c_str());
    if (globals->distance)
        WriteStringToIni(_xor_("1").c_str(), _xor_("C:\\config").c_str(), _xor_("visuals").c_str(), _xor_("distance").c_str());
    else
        WriteStringToIni(_xor_("0").c_str(), _xor_("C:\\config").c_str(), _xor_("visuals").c_str(), _xor_("distance").c_str());
    if (globals->bounding_box)
        WriteStringToIni(_xor_("1").c_str(), _xor_("C:\\config").c_str(), _xor_("visuals").c_str(), _xor_("bounding_box").c_str());
    else
        WriteStringToIni(_xor_("0").c_str(), _xor_("C:\\config").c_str(), _xor_("visuals").c_str(), _xor_("bounding_box").c_str());
    if (globals->naze_fov)
        WriteStringToIni(_xor_("1").c_str(), _xor_("C:\\config").c_str(), _xor_("misc").c_str(), _xor_("crosshair").c_str());
    else
        WriteStringToIni(_xor_("0").c_str(), _xor_("C:\\config").c_str(), _xor_("misc").c_str(), _xor_("crosshair").c_str());
    if (globals->skeletons)
        WriteStringToIni(_xor_("1").c_str(), _xor_("C:\\config").c_str(), _xor_("visuals").c_str(), _xor_("skeleton").c_str());
    else
        WriteStringToIni(_xor_("0").c_str(), _xor_("C:\\config").c_str(), _xor_("visuals").c_str(), _xor_("skeleton").c_str());
    if (globals->DoVisibleCheck)
        WriteStringToIni(_xor_("1").c_str(), _xor_("C:\\config").c_str(), _xor_("visuals").c_str(), _xor_("Vischeck").c_str());
    else
        WriteStringToIni(_xor_("0").c_str(), _xor_("C:\\config").c_str(), _xor_("visuals").c_str(), _xor_("Vischeck").c_str());
    if (globals->target_line)
        WriteStringToIni(_xor_("1").c_str(), _xor_("C:\\config").c_str(), _xor_("aimbot").c_str(), _xor_("Aimline").c_str());
    else
        WriteStringToIni(_xor_("0").c_str(), _xor_("C:\\config").c_str(), _xor_("aimbot").c_str(), _xor_("Aimline").c_str());
    if (globals->Cornerbox)
        WriteStringToIni(_xor_("1").c_str(), _xor_("C:\\config").c_str(), _xor_("visuals").c_str(), _xor_("CornerBox").c_str());
    else
        WriteStringToIni(_xor_("0").c_str(), _xor_("C:\\config").c_str(), _xor_("visuals").c_str(), _xor_("CornerBox").c_str());
    if (globals->outline)
        WriteStringToIni(_xor_("1").c_str(), _xor_("C:\\config").c_str(), _xor_("visuals").c_str(), _xor_("Outline").c_str());
    else
        WriteStringToIni(_xor_("0").c_str(), _xor_("C:\\config").c_str(), _xor_("visuals").c_str(), _xor_("Outline").c_str());
    if (globals->head)
        WriteStringToIni(_xor_("1").c_str(), _xor_("C:\\config").c_str(), _xor_("visuals").c_str(), _xor_("Head").c_str());
    else
        WriteStringToIni(_xor_("0").c_str(), _xor_("C:\\config").c_str(), _xor_("visuals").c_str(), _xor_("Head").c_str());
    if (globals->username)
        WriteStringToIni(_xor_("1").c_str(), _xor_("C:\\config").c_str(), _xor_("visuals").c_str(), _xor_("name").c_str());
    else
        WriteStringToIni(_xor_("0").c_str(), _xor_("C:\\config").c_str(), _xor_("visuals").c_str(), _xor_("name").c_str());
    if (globals->weapon_esp)
        WriteStringToIni(_xor_("1").c_str(), _xor_("C:\\config").c_str(), _xor_("visuals").c_str(), _xor_("weapon_esp").c_str());
    else
        WriteStringToIni(_xor_("0").c_str(), _xor_("C:\\config").c_str(), _xor_("visuals").c_str(), _xor_("weapon_esp").c_str());
    if (globals->weapon_cfg)
        WriteStringToIni(_xor_("1").c_str(), _xor_("C:\\config").c_str(), _xor_("aimbot").c_str(), _xor_("weapon_cfgs").c_str());
    else
        WriteStringToIni(_xor_("0").c_str(), _xor_("C:\\config").c_str(), _xor_("aimbot").c_str(), _xor_("weapon_cfgs").c_str());
    if (globals->normal_fov)
        WriteStringToIni(_xor_("1").c_str(), _xor_("C:\\config").c_str(), _xor_("misc").c_str(), _xor_("circle_fov").c_str());
    else
        WriteStringToIni(_xor_("0").c_str(), _xor_("C:\\config").c_str(), _xor_("misc").c_str(), _xor_("circle_fov").c_str());
    if (globals->dick_fov)
        WriteStringToIni(_xor_("1").c_str(), _xor_("C:\\config").c_str(), _xor_("misc").c_str(), _xor_("dic_fov").c_str());
    else
        WriteStringToIni(_xor_("0").c_str(), _xor_("C:\\config").c_str(), _xor_("misc").c_str(), _xor_("dick_fov").c_str());
    if (globals->chrome_fov)
        WriteStringToIni(_xor_("1").c_str(), _xor_("C:\\config").c_str(), _xor_("misc").c_str(), _xor_("chrome_fov").c_str());
    else
        WriteStringToIni(_xor_("0").c_str(), _xor_("C:\\config").c_str(), _xor_("misc").c_str(), _xor_("chrome_fov").c_str());
    if (globals->star_fov)
        WriteStringToIni(_xor_("1").c_str(), _xor_("C:\\config").c_str(), _xor_("aimbot").c_str(), _xor_("star_fov").c_str());
    else
        WriteStringToIni(_xor_("0").c_str(), _xor_("C:\\config").c_str(), _xor_("aimbot").c_str(), _xor_("star_fov").c_str());
    if (globals->triangle_fov)
        WriteStringToIni(_xor_("1").c_str(), _xor_("C:\\config").c_str(), _xor_("misc").c_str(), _xor_("triangle_fov").c_str());
    else
        WriteStringToIni(_xor_("0").c_str(), _xor_("C:\\config").c_str(), _xor_("misc").c_str(), _xor_("triangle_fov").c_str());
    if (globals->HeadBone)
        WriteStringToIni(_xor_("1").c_str(), _xor_("C:\\config").c_str(), _xor_("aimbot").c_str(), _xor_("head_bone").c_str());
    else
        WriteStringToIni(_xor_("0").c_str(), _xor_("C:\\config").c_str(), _xor_("aimbot").c_str(), _xor_("head_bone").c_str());
    if (globals->ChestBone)
        WriteStringToIni(_xor_("1").c_str(), _xor_("C:\\config").c_str(), _xor_("aimbot").c_str(), _xor_("chest_bone").c_str());
    else
        WriteStringToIni(_xor_("0").c_str(), _xor_("C:\\config").c_str(), _xor_("aimbot").c_str(), _xor_("chest_bone").c_str());
    if (globals->PelvisBone)
        WriteStringToIni(_xor_("1").c_str(), _xor_("C:\\config").c_str(), _xor_("aimbot").c_str(), _xor_("pelvis_bone").c_str());
    else
        WriteStringToIni(_xor_("0").c_str(), _xor_("C:\\config").c_str(), _xor_("aimbot").c_str(), _xor_("pelvis_bone").c_str());
    if (globals->NeckBone)
        WriteStringToIni(_xor_("1").c_str(), _xor_("C:\\config").c_str(), _xor_("aimbot").c_str(), _xor_("neck_bone").c_str());
    else
        WriteStringToIni(_xor_("0").c_str(), _xor_("C:\\config").c_str(), _xor_("aimbot").c_str(), _xor_("neck_bone").c_str());
    if (globals->target_text)
        WriteStringToIni(_xor_("1").c_str(), _xor_("C:\\config").c_str(), _xor_("aimbot").c_str(), _xor_("target_text").c_str());
    else
        WriteStringToIni(_xor_("0").c_str(), _xor_("C:\\config").c_str(), _xor_("aimbot").c_str(), _xor_("target_text").c_str());
    if (rifle::render_fov)
        WriteStringToIni(_xor_("1").c_str(), _xor_("C:\\config").c_str(), _xor_("rifle").c_str(), _xor_("rifle_show_fov").c_str());
    else
        WriteStringToIni(_xor_("0").c_str(), _xor_("C:\\config").c_str(), _xor_("rifle").c_str(), _xor_("rifle_show_fov").c_str());
    if (shotgun::render_fov)
        WriteStringToIni(_xor_("1").c_str(), _xor_("C:\\config").c_str(), _xor_("shotgun").c_str(), _xor_("shotgun_show_fov").c_str());
    else
        WriteStringToIni(_xor_("0").c_str(), _xor_("C:\\config").c_str(), _xor_("shotgun").c_str(), _xor_("shotgun_show_fov").c_str());
    if (smg::render_fov)
        WriteStringToIni(_xor_("1").c_str(), _xor_("C:\\config").c_str(), _xor_("smg").c_str(), _xor_("smg_show_fov").c_str());
    else
        WriteStringToIni(_xor_("0").c_str(), _xor_("C:\\config").c_str(), _xor_("smg").c_str(), _xor_("smg_show_fov").c_str());
    if (sniper::render_fov)
        WriteStringToIni(_xor_("1").c_str(), _xor_("C:\\config").c_str(), _xor_("sniper").c_str(), _xor_("sinper_show_fov").c_str());
    else
        WriteStringToIni(_xor_("0").c_str(), _xor_("C:\\config").c_str(), _xor_("sniper").c_str(), _xor_("sinper_show_fov").c_str());
    if (globals->pickups)
        WriteStringToIni(_xor_("1").c_str(), _xor_("C:\\config").c_str(), _xor_("world").c_str(), _xor_("pickups").c_str());
    else
        WriteStringToIni(_xor_("0").c_str(), _xor_("C:\\config").c_str(), _xor_("world").c_str(), _xor_("pickups").c_str());
    if (globals->chests)
        WriteStringToIni(_xor_("1").c_str(), _xor_("C:\\config").c_str(), _xor_("world").c_str(), _xor_("chests").c_str());
    else
        WriteStringToIni(_xor_("0").c_str(), _xor_("C:\\config").c_str(), _xor_("world").c_str(), _xor_("chests").c_str());
    if (globals->vehicle)
        WriteStringToIni(_xor_("1").c_str(), _xor_("C:\\config").c_str(), _xor_("world").c_str(), _xor_("vehicle").c_str());
    else
        WriteStringToIni(_xor_("0").c_str(), _xor_("C:\\config").c_str(), _xor_("world").c_str(), _xor_("vehicle").c_str());
    if (globals->Lamma)
        WriteStringToIni(_xor_("1").c_str(), _xor_("C:\\config").c_str(), _xor_("world").c_str(), _xor_("Lamma").c_str());
    else
        WriteStringToIni(_xor_("0").c_str(), _xor_("C:\\config").c_str(), _xor_("world").c_str(), _xor_("Lamma").c_str());
    if (globals->uncommon)
        WriteStringToIni(_xor_("1").c_str(), _xor_("C:\\config").c_str(), _xor_("world").c_str(), _xor_("uncommon").c_str());
    else
        WriteStringToIni(_xor_("0").c_str(), _xor_("C:\\config").c_str(), _xor_("world").c_str(), _xor_("uncommon").c_str());
    if (globals->commom)
        WriteStringToIni(_xor_("1").c_str(), _xor_("C:\\config").c_str(), _xor_("world").c_str(), _xor_("commom").c_str());
    else
        WriteStringToIni(_xor_("0").c_str(), _xor_("C:\\config").c_str(), _xor_("world").c_str(), _xor_("commom").c_str());
    if (globals->rare)
        WriteStringToIni(_xor_("1").c_str(), _xor_("C:\\config").c_str(), _xor_("world").c_str(), _xor_("rare").c_str());
    else
        WriteStringToIni(_xor_("0").c_str(), _xor_("C:\\config").c_str(), _xor_("world").c_str(), _xor_("rare").c_str());
    if (globals->epic)
        WriteStringToIni(_xor_("1").c_str(), _xor_("C:\\config").c_str(), _xor_("world").c_str(), _xor_("epic").c_str());
    else
        WriteStringToIni(_xor_("0").c_str(), _xor_("C:\\config").c_str(), _xor_("world").c_str(), _xor_("epic").c_str());

    if (globals->mythic)
        WriteStringToIni(_xor_("1").c_str(), _xor_("C:\\config").c_str(), _xor_("world").c_str(), _xor_("mythic").c_str());
    else
        WriteStringToIni(_xor_("0").c_str(), _xor_("C:\\config").c_str(), _xor_("world").c_str(), _xor_("mythic").c_str());

    if (globals->lengendery)
        WriteStringToIni(_xor_("1").c_str(), _xor_("C:\\config").c_str(), _xor_("world").c_str(), _xor_("lengendery").c_str());
    else
        WriteStringToIni(_xor_("0").c_str(), _xor_("C:\\config").c_str(), _xor_("world").c_str(), _xor_("lengendery").c_str());
    WriteStringToIni(std::to_string(globals->field_of_view), _xor_("C:\\config").c_str(), _xor_("aimbot").c_str(), _xor_("aimfov").c_str());
    WriteStringToIni(std::to_string(globals->smooth), _xor_("C:\\config").c_str(), _xor_("aimbot").c_str(), _xor_("smooth").c_str());
    WriteStringToIni(std::to_string(globals->custom_delay), _xor_("C:\\config").c_str(), _xor_("aimbot").c_str(), _xor_("trig_custom_delay").c_str());
    WriteStringToIni(std::to_string(globals->maximum_distance), _xor_("C:\\config").c_str(), _xor_("aimbot").c_str(), _xor_("max_trig_distance").c_str());
    WriteStringToIni(std::to_string(globals->aimbot_key), _xor_("C:\\config").c_str(), _xor_("aimbot").c_str(), _xor_("aim_key").c_str());
    WriteStringToIni(std::to_string(globals->triggerbot_key), _xor_("C:\\config").c_str(), _xor_("aimbot").c_str(), _xor_("trigger_key").c_str());
    WriteStringToIni(std::to_string(rifle::aim_fov), _xor_("C:\\config").c_str(), _xor_("rifle").c_str(), _xor_("rifle_fov").c_str());
    WriteStringToIni(std::to_string(rifle::smooth), _xor_("C:\\config").c_str(), _xor_("rifle").c_str(), _xor_("rifle_smooth").c_str());
    WriteStringToIni(std::to_string(shotgun::aim_fov), _xor_("C:\\config").c_str(), _xor_("shogtun").c_str(), _xor_("shogtun_fov").c_str());
    WriteStringToIni(std::to_string(shotgun::smooth), _xor_("C:\\config").c_str(), _xor_("shogtun").c_str(), _xor_("shogtun_smooth").c_str());
    WriteStringToIni(std::to_string(smg::aim_fov), _xor_("C:\\config").c_str(), _xor_("smg").c_str(), _xor_("smg_fov").c_str());
    WriteStringToIni(std::to_string(smg::smooth), _xor_("C:\\config").c_str(), _xor_("smg").c_str(), _xor_("smg_smooth").c_str());
    WriteStringToIni(std::to_string(sniper::aim_fov), _xor_("C:\\config").c_str(), _xor_("sniper").c_str(), _xor_("sniper_fov").c_str());
    WriteStringToIni(std::to_string(sniper::smooth), _xor_("C:\\config").c_str(), _xor_("sniper").c_str(), _xor_("sniper_smooth").c_str());
    WriteStringToIni(std::to_string(globals->max_distance1), _xor_("C:\\config").c_str(), _xor_("world").c_str(), _xor_("pickup_dist").c_str());
    WriteStringToIni(std::to_string(globals->max_distance2), _xor_("C:\\config").c_str(), _xor_("world").c_str(), _xor_("vehicle_dist").c_str());
    WriteStringToIni(std::to_string(globals->max_distance3), _xor_("C:\\config").c_str(), _xor_("world").c_str(), _xor_("lamma_dist").c_str());
    WriteStringToIni(std::to_string(globals->max_distance4), _xor_("C:\\config").c_str(), _xor_("world").c_str(), _xor_("chest_dist").c_str());


    WriteStringToIni(FloatArrayToString(PlayerColor::BoxVisible, 4), _xor_("C:\\config").c_str(), _xor_("colors").c_str(), _xor_("BoxVisible").c_str());
    WriteStringToIni(FloatArrayToString(PlayerColor::BoxNotVisible, 4), _xor_("C:\\config").c_str(), _xor_("colors").c_str(), _xor_("BoxNotVisible").c_str());
    WriteStringToIni(FloatArrayToString(PlayerColor::targetcol, 4), _xor_("C:\\config").c_str(), _xor_("colors").c_str(), _xor_("targetcol").c_str());
    WriteStringToIni(FloatArrayToString(PlayerColor::accentcolor, 4), _xor_("C:\\config").c_str(), _xor_("colors").c_str(), _xor_("accentcolor").c_str());
    WriteStringToIni(FloatArrayToString(PlayerColor::SkeletonVisible, 4), _xor_("C:\\config").c_str(), _xor_("colors").c_str(), _xor_("SkeletonVisible").c_str());
    WriteStringToIni(FloatArrayToString(PlayerColor::SkeletonNotVisible, 4), _xor_("C:\\config").c_str(), _xor_("colors").c_str(), _xor_("SkeletonNotVisible").c_str());
    WriteStringToIni(FloatArrayToString(PlayerColor::SnaplineVisible, 4), _xor_("C:\\config").c_str(), _xor_("colors").c_str(), _xor_("SnaplineVisible").c_str());
    WriteStringToIni(FloatArrayToString(PlayerColor::SnaplineNotVisible, 4), _xor_("C:\\config").c_str(), _xor_("colors").c_str(), _xor_("SnaplineNotVisible").c_str());
    WriteStringToIni(FloatArrayToString(PlayerColor::TopTextVisible, 4), _xor_("C:\\config").c_str(), _xor_("colors").c_str(), _xor_("TopTextVisible").c_str());
    WriteStringToIni(FloatArrayToString(PlayerColor::TopTextNotVisible, 4), _xor_("C:\\config").c_str(), _xor_("colors").c_str(), _xor_("TopTextNotVisible").c_str());
    WriteStringToIni(FloatArrayToString(PlayerColor::BottomTextVisible, 4), _xor_("C:\\config").c_str(), _xor_("colors").c_str(), _xor_("BottomTextVisible").c_str());
    WriteStringToIni(FloatArrayToString(PlayerColor::BottomTextNotVisible, 4), _xor_("C:\\config").c_str(), _xor_("colors").c_str(), _xor_("BottomTextNotVisible").c_str());
}

std::vector<float> StringToFloatArray(const std::string& str) {
    std::vector<float> result;
    std::istringstream iss(str);
    std::string token;

    while (std::getline(iss, token, ',')) {
        result.push_back(std::stof(token));
    }

    return result;
}

void ReadColorsFromIni(std::string file, std::string app, std::string key, float* colorArray, int colorArraySize) {
    char buf[100];
    GetPrivateProfileStringA(app.c_str(), key.c_str(), _xor_("NULL").c_str(), buf, 100, file.c_str());

    if (strcmp(buf, _xor_("NULL").c_str()) != 0) {
        std::vector<float> colors = StringToFloatArray(buf);
        if (colors.size() == colorArraySize) {
            // Apply the loaded colors to the colorArray
            for (int i = 0; i < colorArraySize; ++i) {
                colorArray[i] = colors[i];
            }
        }
        else {
            // Handle error: Incorrect number of color components in the loaded string
            system(_xor_("cls").c_str());
            std::cout << _xor_(" [").c_str() << _xor_("ERR - 15").c_str() << _xor_("] - Incorrect number of color components.").c_str();
            Sleep(5000);
            exit(0);
        }
    }
}

void LoadConfig()
{
    if (ReadStringFromIni(_xor_("C:\\config").c_str(), _xor_("aimbot").c_str(), _xor_("aimbot").c_str()) == _xor_("1").c_str())
        globals->aimbot = true;
    else
        globals->aimbot = false;

    if (ReadStringFromIni(_xor_("C:\\config").c_str(), _xor_("aimbot").c_str(), _xor_("drawfov").c_str()) == _xor_("1").c_str())
        globals->render_field_of_view = true;
    else
        globals->render_field_of_view = false;

    if (ReadStringFromIni(_xor_("C:\\config").c_str(), _xor_("aimbot").c_str(), _xor_("triggerbot").c_str()) == _xor_("1").c_str())
        globals->triggerbot = true;
    else
        globals->triggerbot = false;

    if (ReadStringFromIni(_xor_("C:\\config").c_str(), _xor_("visuals").c_str(), _xor_("distance").c_str()) == _xor_("1").c_str())
        globals->distance = true;
    else
        globals->distance = false;

    if (ReadStringFromIni(_xor_("C:\\config").c_str(), _xor_("visuals").c_str(), _xor_("bounding_box").c_str()) == _xor_("1").c_str())
        globals->bounding_box = true;
    else
        globals->bounding_box = false;

    if (ReadStringFromIni(_xor_("C:\\config").c_str(), _xor_("misc").c_str(), _xor_("crosshair").c_str()) == _xor_("1").c_str())
        globals->naze_fov = true;
    else
        globals->naze_fov = false;

    if (ReadStringFromIni(_xor_("C:\\config").c_str(), _xor_("visuals").c_str(), _xor_("skeleton").c_str()) == _xor_("1").c_str())
        globals->skeletons = true;
    else
        globals->skeletons = false;

    if (ReadStringFromIni(_xor_("C:\\config").c_str(), _xor_("visuals").c_str(), _xor_("Vischeck").c_str()) == _xor_("1").c_str())
        globals->DoVisibleCheck = true;
    else
        globals->DoVisibleCheck = false;

    if (ReadStringFromIni(_xor_("C:\\config").c_str(), _xor_("aimbot").c_str(), _xor_("Aimline").c_str()) == _xor_("1").c_str())
        globals->target_line = true;
    else
        globals->target_line = false;

    if (ReadStringFromIni(_xor_("C:\\config").c_str(), _xor_("visuals").c_str(), _xor_("CornerBox").c_str()) == _xor_("1").c_str())
        globals->Cornerbox = true;
    else
        globals->Cornerbox = false;

    if (ReadStringFromIni(_xor_("C:\\.config").c_str(), _xor_("visuals").c_str(), _xor_("Outline").c_str()) == _xor_("1").c_str())
        globals->outline = true;
    else
        globals->outline = false;

    if (ReadStringFromIni(_xor_("C:\\config").c_str(), _xor_("visuals").c_str(), _xor_("Head").c_str()) == _xor_("1").c_str())
        globals->head = true;
    else
        globals->head = false;

    if (ReadStringFromIni(_xor_("C:\\config").c_str(), _xor_("visuals").c_str(), _xor_("name").c_str()) == _xor_("1").c_str())
        globals->username = true;
    else
        globals->username = false;

    if (ReadStringFromIni(_xor_("C:\\config").c_str(), _xor_("visuals").c_str(), _xor_("weapon_esp").c_str()) == _xor_("1").c_str())
        globals->weapon_esp = true;
    else
        globals->weapon_esp = false;

    if (ReadStringFromIni(_xor_("C:\\config").c_str(), _xor_("aimbot").c_str(), _xor_("weapon_cfgs").c_str()) == _xor_("1").c_str())
        globals->weapon_cfg = true;
    else
        globals->weapon_cfg = false;

    if (ReadStringFromIni(_xor_("C:\\config").c_str(), _xor_("misc").c_str(), _xor_("circle_fov").c_str()) == _xor_("1").c_str())
        globals->normal_fov = true;
    else
        globals->normal_fov = false;

    if (ReadStringFromIni(_xor_("C:\\config").c_str(), _xor_("misc").c_str(), _xor_("dick_fov").c_str()) == _xor_("1").c_str())
        globals->dick_fov = true;
    else
        globals->dick_fov = false;

    if (ReadStringFromIni(_xor_("C:\\config").c_str(), _xor_("misc").c_str(), _xor_("chrome_fov").c_str()) == _xor_("1").c_str())
        globals->chrome_fov = true;
    else
        globals->chrome_fov = false;

    if (ReadStringFromIni(_xor_("C:\\config").c_str(), _xor_("aimbot").c_str(), _xor_("star_fov").c_str()) == _xor_("1").c_str())
        globals->star_fov = true;
    else
        globals->star_fov = false;

    if (ReadStringFromIni(_xor_("C:\\config").c_str(), _xor_("misc").c_str(), _xor_("triangle_fov").c_str()) == _xor_("1").c_str())
        globals->triangle_fov = true;
    else
        globals->triangle_fov = false;

    if (ReadStringFromIni(_xor_("C:\\config").c_str(), _xor_("aimbot").c_str(), _xor_("head_bone").c_str()) == _xor_("1").c_str())
        globals->HeadBone = true;
    else
        globals->HeadBone = false;

    if (ReadStringFromIni(_xor_("C:\\config").c_str(), _xor_("aimbot").c_str(), _xor_("chest_bone").c_str()) == _xor_("1").c_str())
        globals->ChestBone = true;
    else
        globals->ChestBone = false;

    if (ReadStringFromIni(_xor_("C:\\config").c_str(), _xor_("aimbot").c_str(), _xor_("pelvis_bone").c_str()) == _xor_("1").c_str())
        globals->PelvisBone = true;
    else
        globals->PelvisBone = false;

    if (ReadStringFromIni(_xor_("C:\\config").c_str(), _xor_("aimbot").c_str(), _xor_("neck_bone").c_str()) == _xor_("1").c_str())
        globals->NeckBone = true;
    else
        globals->NeckBone = false;

    if (ReadStringFromIni(_xor_("C:\\config").c_str(), _xor_("aimbot").c_str(), _xor_("target_text").c_str()) == _xor_("1").c_str())
        globals->target_text = true;
    else
        globals->target_text = false;

    if (ReadStringFromIni(_xor_("C:\\config").c_str(), _xor_("rifle").c_str(), _xor_("rifle_show_fov").c_str()) == _xor_("1").c_str())
        rifle::render_fov = true;
    else
        rifle::render_fov = false;
    if (ReadStringFromIni(_xor_("C:\\config").c_str(), _xor_("shotgun").c_str(), _xor_("shotgun_show_fov").c_str()) == _xor_("1").c_str())
        shotgun::render_fov = true;
    else
        shotgun::render_fov = false;
    if (ReadStringFromIni(_xor_("C:\\config").c_str(), _xor_("smg").c_str(), _xor_("smg_show_fov").c_str()) == _xor_("1").c_str())
        smg::render_fov = true;
    else
        smg::render_fov = false;
    if (ReadStringFromIni(_xor_("C:\\config").c_str(), _xor_("sniper").c_str(), _xor_("sniper_show_fov").c_str()) == _xor_("1").c_str())
        sniper::render_fov = true;
    else
        sniper::render_fov = false;
    if (ReadStringFromIni(_xor_("C:\\config").c_str(), _xor_("world").c_str(), _xor_("pickups").c_str()) == _xor_("1").c_str())
        globals->pickups = true;
    else
        globals->pickups = false;
    if (ReadStringFromIni(_xor_("C:\\config").c_str(), _xor_("world").c_str(), _xor_("vehicle").c_str()) == _xor_("1").c_str())
        globals->vehicle = true;
    else
        globals->vehicle = false;
    if (ReadStringFromIni(_xor_("C:\\config").c_str(), _xor_("world").c_str(), _xor_("Lamma").c_str()) == _xor_("1").c_str())
        globals->Lamma = true;
    else
        globals->Lamma = false;
    if (ReadStringFromIni(_xor_("C:\\config").c_str(), _xor_("world").c_str(), _xor_("chests").c_str()) == _xor_("1").c_str())
        globals->chests = true;
    else
        globals->chests = false;
    if (ReadStringFromIni(_xor_("C:\\config").c_str(), _xor_("world").c_str(), _xor_("uncommon").c_str()) == _xor_("1").c_str())
        globals->uncommon = true;
    else
        globals->uncommon = false;
    if (ReadStringFromIni(_xor_("C:\\config").c_str(), _xor_("world").c_str(), _xor_("commom").c_str()) == _xor_("1").c_str())
        globals->commom = true;
    else
        globals->commom = false;
    if (ReadStringFromIni(_xor_("C:\\config").c_str(), _xor_("world").c_str(), _xor_("rare").c_str()) == _xor_("1").c_str())
        globals->rare = true;
    else
        globals->rare = false;
    if (ReadStringFromIni(_xor_("C:\\config").c_str(), _xor_("world").c_str(), _xor_("epic").c_str()) == _xor_("1").c_str())
        globals->epic = true;
    else
        globals->epic = false;
    if (ReadStringFromIni(_xor_("C:\\config").c_str(), _xor_("world").c_str(), _xor_("lengendery").c_str()) == _xor_("1").c_str())
        globals->lengendery = true;
    else
        globals->lengendery = false;
    if (ReadStringFromIni(_xor_("C:\\config").c_str(), _xor_("world").c_str(), _xor_("mythic").c_str()) == _xor_("1").c_str())
        globals->mythic = true;
    else
        globals->mythic = false;






    ReadStringFromIni_Float(_xor_("C:\\config").c_str(), _xor_("aimbot").c_str(), _xor_("aimfov").c_str(), 4);
    globals->field_of_view;
    ReadStringFromIni_Float(_xor_("C:\\config").c_str(), _xor_("aimbot").c_str(), _xor_("smooth").c_str(), 5);
    globals->smooth;
    ReadStringFromIni_Float(_xor_("C:\\config").c_str(), _xor_("aimbot").c_str(), _xor_("trig_custom_delay").c_str(), 6);
    globals->custom_delay;
    ReadStringFromIni_Float(_xor_("C:\\config").c_str(), _xor_("aimbot").c_str(), _xor_("max_trig_distance").c_str(), 7);
    globals->maximum_distance;
    ReadStringFromIni_Float(_xor_("C:\\config").c_str(), _xor_("aimbot").c_str(), _xor_("aim_key").c_str(), 8);
    globals->aimbot_key;
    ReadStringFromIni_Float(_xor_("C:\\config").c_str(), _xor_("aimbot").c_str(), _xor_("trigger_key").c_str(), 9);
    globals->triggerbot_key;
    ReadStringFromIni_Float(_xor_("C:\\config").c_str(), _xor_("rifle").c_str(), _xor_("rifle_fov").c_str(), 10);
    rifle::aim_fov;
    ReadStringFromIni_Float(_xor_("C:\\config").c_str(), _xor_("rifle").c_str(), _xor_("rifle_smooth").c_str(), 11);
    rifle::smooth;
    ReadStringFromIni_Float(_xor_("C:\\config").c_str(), _xor_("shogtun").c_str(), _xor_("shogtun_fov").c_str(), 12);
    shotgun::aim_fov;
    ReadStringFromIni_Float(_xor_("C:\\config").c_str(), _xor_("shogtun").c_str(), _xor_("shogtun_smooth").c_str(), 13);
    shotgun::smooth;
    ReadStringFromIni_Float(_xor_("C:\\config").c_str(), _xor_("smg").c_str(), _xor_("smg_fov").c_str(), 14);
    smg::aim_fov;
    ReadStringFromIni_Float(_xor_("C:\\config").c_str(), _xor_("smg").c_str(), _xor_("smg_smooth").c_str(), 15);
    smg::smooth;
    ReadStringFromIni_Float(_xor_("C:\\config").c_str(), _xor_("sniper").c_str(), _xor_("sniper_fov").c_str(), 16);
    sniper::aim_fov;
    ReadStringFromIni_Float(_xor_("C:\\config").c_str(), _xor_("sniper").c_str(), _xor_("sniper_smooth").c_str(), 17);
    sniper::smooth;
    ReadStringFromIni_Float(_xor_("C:\\config").c_str(), _xor_("world").c_str(), _xor_("pickup_dist").c_str(), 18);
    globals->max_distance1;
    ReadStringFromIni_Float(_xor_("C:\\config").c_str(), _xor_("world").c_str(), _xor_("vehicle_dist").c_str(), 19);
    globals->max_distance2;
    ReadStringFromIni_Float(_xor_("C:\\config").c_str(), _xor_("world").c_str(), _xor_("lamma_dist").c_str(), 20);
    globals->max_distance3;
    ReadStringFromIni_Float(_xor_("C:\\config").c_str(), _xor_("world").c_str(), _xor_("chest_dist").c_str(), 21);
    globals->max_distance4;
    ReadColorsFromIni(_xor_("C:\\config").c_str(), _xor_("colors").c_str(), _xor_("BoxVisible").c_str(), PlayerColor::BoxVisible, 4);
    ReadColorsFromIni(_xor_("C:\\config").c_str(), _xor_("colors").c_str(), _xor_("BoxNotVisible").c_str(), PlayerColor::BoxNotVisible, 4);
    ReadColorsFromIni(_xor_("C:\\config").c_str(), _xor_("colors").c_str(), _xor_("targetcol").c_str(), PlayerColor::targetcol, 4);
    ReadColorsFromIni(_xor_("C:\\config").c_str(), _xor_("colors").c_str(), _xor_("accentcolor").c_str(), PlayerColor::accentcolor, 4);
    ReadColorsFromIni(_xor_("C:\\config").c_str(), _xor_("colors").c_str(), _xor_("SkeletonVisible").c_str(), PlayerColor::SkeletonVisible, 4);
    ReadColorsFromIni(_xor_("C:\\config").c_str(), _xor_("colors").c_str(), _xor_("SkeletonNotVisible").c_str(), PlayerColor::SkeletonNotVisible, 4);
    ReadColorsFromIni(_xor_("C:\\config").c_str(), _xor_("colors").c_str(), _xor_("SnaplineVisible").c_str(), PlayerColor::SnaplineVisible, 4);
    ReadColorsFromIni(_xor_("C:\\config").c_str(), _xor_("colors").c_str(), _xor_("SnaplineNotVisible").c_str(), PlayerColor::SnaplineNotVisible, 4);
    ReadColorsFromIni(_xor_("C:\\config").c_str(), _xor_("colors").c_str(), _xor_("TopTextVisible").c_str(), PlayerColor::TopTextVisible, 4);
    ReadColorsFromIni(_xor_("C:\\config").c_str(), _xor_("colors").c_str(), _xor_("TopTextNotVisible").c_str(), PlayerColor::TopTextNotVisible, 4);
    ReadColorsFromIni(_xor_("C:\\config").c_str(), _xor_("colors").c_str(), _xor_("BottomTextVisible").c_str(), PlayerColor::BottomTextVisible, 4);
    ReadColorsFromIni(_xor_("C:\\config").c_str(), _xor_("colors").c_str(), _xor_("BottomTextNotVisible").c_str(), PlayerColor::BottomTextNotVisible, 4);

}




inline static int keystatus = 0;

inline static int realkey = 0;

inline static int realkey1 = 0;
inline static int keystatus1 = 0;
inline static int keystatus2 = 0;
inline static int keystatus3 = 0;
inline static int keystatus4 = 0;
char* name1;

inline int aimkey = 0;
inline bool GetKey(int key)
{
    realkey = key;
    return true;
}
inline void ChangeKey(void* blank)
{
    keystatus = 1;
    while (true)
    {
        for (int i = 0; i < 0x87; i++)
        {
            if (GetAsyncKeyState_Spoofed(i) & 0x8000)
            {
                aimkey = i;
                keystatus = 0;
                return;
            }
        }
    }
}


inline bool GetKey1(int key)
{
    realkey1 = key;
    return true;
}
inline void ChangeKey1(void* blank)
{
    keystatus1 = 1;
    while (true)
    {
        for (int i = 0; i < 0x87; i++)
        {
            if (GetAsyncKeyState_Spoofed(i) & 0x8000)
            {
                rifle::aimkey = i;
                keystatus1 = 0;
                return;
            }
        }
    }
}

inline bool GetKey2(int key)
{
    realkey1 = key;
    return true;
}
inline void ChangeKey2(void* blank)
{
    keystatus2 = 1;
    while (true)
    {
        for (int i = 0; i < 0x87; i++)
        {
            if (GetAsyncKeyState_Spoofed(i) & 0x8000)
            {
                smg::aimkey = i;
                keystatus2 = 0;
                return;
            }
        }
    }
}


inline void ChangeKey3(void* blank)
{
    keystatus3 = 1;
    while (true)
    {
        for (int i = 0; i < 0x87; i++)
        {
            if (GetAsyncKeyState_Spoofed(i) & 0x8000)
            {
                shotgun::aimkey = i;
                keystatus3 = 0;
                return;
            }
        }
    }
}



inline void ChangeKey4(void* blank)
{
    keystatus4 = 1;
    while (true)
    {
        for (int i = 0; i < 0x87; i++)
        {
            if (GetAsyncKeyState_Spoofed(i) & 0x8000)
            {
                sniper::aimkey = i;
                keystatus4 = 0;
                return;
            }
        }
    }
}



inline void DrawBox(float X, float Y, float W, float H, const ImU32& color, int thickness)
{
    ImGui::GetForegroundDrawList()->AddRect(ImVec2(X, Y), ImVec2(X + W, Y + H), ImGui::GetColorU32(color), thickness);
}

static const char* keyNames[] =
{

    "Keybind",
    "Left Mouse",
    "Right Mouse",
    "Cancel",
    "Middle Mouse",
    "Mouse 5",
    "Mouse 4",
    "",
    "Backspace",
    "Tab",
    "",
    "",
    "Clear",
    "Enter",
    "",
    "",
    "Shift",
    "Control",
    "Alt",
    "Pause",
    "Caps",
    "",
    "",
    "",
    "",
    "",
    "",
    "Escape",
    "",
    "",
    "",
    "",
    "Space",
    "Page Up",
    "Page Down",
    "End",
    "Home",
    "Left",
    "Up",
    "Right",
    "Down",
    "",
    "",
    "",
    "Print",
    "Insert",
    "Delete",
    "",
    "0",
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "A",
    "B",
    "C",
    "D",
    "E",
    "F",
    "G",
    "H",
    "I",
    "J",
    "K",
    "L",
    "M",
    "N",
    "O",
    "P",
    "Q",
    "R",
    "S",
    "T",
    "U",
    "V",
    "W",
    "X",
    "Y",
    "Z",
    "",
    "",
    "",
    "",
    "",
    "Numpad 0",
    "Numpad 1",
    "Numpad 2",
    "Numpad 3",
    "Numpad 4",
    "Numpad 5",
    "Numpad 6",
    "Numpad 7",
    "Numpad 8",
    "Numpad 9",
    "Multiply",
    "Add",
    "",
    "Subtract",
    "Decimal",
    "Divide",
    "F1",
    "F2",
    "F3",
    "F4",
    "F5",
    "F6",
    "F7",
    "F8",
    "F9",
    "F10",
    "F11",
    "F12",
};

inline static bool Items_ArrayGetter(void* data, int idx, const char** out_text)
{
    const char* const* items = (const char* const*)data;
    if (out_text)
        *out_text = items[idx];
    return true;
}
inline void HotkeyButton(int aimkey, void* changekey, int status)
{
    const char* preview_value = NULL;
    if (aimkey >= 0 && aimkey < IM_ARRAYSIZE(keyNames))
        Items_ArrayGetter(keyNames, aimkey, &preview_value);
    std::string aimkeys;
    if (preview_value == NULL)
        aimkeys = (("Select Key"));
    else
        aimkeys = preview_value;

    if (status == 1)
    {

        aimkeys = (("Press the Key"));
    }
    if (ImGui::Button(aimkeys.c_str(), ImVec2(155, 40)))
    {
        if (status == 0)
        {
            CreateThread(0, 0, (LPTHREAD_START_ROUTINE)changekey, nullptr, 0, nullptr);
        }
    }
}

ImFont* LexendDecaFont;
ImFont* IconFont;
ImFont* IconFontLogs;
ImFont* InterMedium;
ImFont* TestFont;

ImFont* InterMediumone;
auto s = ImVec2{}, p = ImVec2{}, gs = ImVec2{ 672, 470 };

IDirect3DTexture9* bgs = nullptr;
ID3D11ShaderResourceView* logo = nullptr;
ID3D11ShaderResourceView* normal = nullptr;
ID3D11ShaderResourceView* skeleton = nullptr;
ID3D11ShaderResourceView* head = nullptr;
ID3D11ShaderResourceView* headskel = nullptr;

ID3D11ShaderResourceView* circle = nullptr;

IDirect3DTexture9* foto = nullptr;
IDirect3DTexture9* merfthefurry = nullptr;
IDirect3DTexture9* ghoul = nullptr;
HWND window_handle;

ID3D11Device* d3d_device;
ID3D11DeviceContext* d3d_device_ctx;
IDXGISwapChain* d3d_swap_chain;
ID3D11RenderTargetView* d3d_render_target;
D3DPRESENT_PARAMETERS d3d_present_params;
ID3D11ShaderResourceView* playermodel = nullptr;
ImDrawList* drawlist;
ImVec2 pos;
ImFont* descriptionfont;
ImFont* icons;
ImDrawList* tabdrawlist;
ImFont* comboarrow;
int tabs = 0;



namespace Variables {
    int ActiveTab = 1;
}
static const char* KeyNames1[] = {
    "Aimbot Bot Key",
    "VK_LBUTTON",
    "VK_RBUTTON",
    "VK_CANCEL",
    "VK_MBUTTON",
    "VK_XBUTTON1",
    "VK_XBUTTON2",
    "Unknown",
    "VK_BACK",
    "VK_TAB",
    "Unknown",
    "Unknown",
    "VK_CLEAR",
    "VK_RETURN",
    "Unknown",
    "Unknown",
    "VK_SHIFT",
    "VK_CONTROL",
    "VK_MENU",
    "VK_PAUSE",
    "VK_CAPITAL",
    "VK_KANA",
    "Unknown",
    "VK_JUNJA",
    "VK_FINAL",
    "VK_KANJI",
    "Unknown",
    "VK_ESCAPE",
    "VK_CONVERT",
    "VK_NONCONVERT",
    "VK_ACCEPT",
    "VK_MODECHANGE",
    "VK_SPACE",
    "VK_PRIOR",
    "VK_NEXT",
    "VK_END",
    "VK_HOME",
    "VK_LEFT",
    "VK_UP",
    "VK_RIGHT",
    "VK_DOWN",
    "VK_SELECT",
    "VK_PRINT",
    "VK_EXECUTE",
    "VK_SNAPSHOT",
    "VK_INSERT",
    "VK_DELETE",
    "VK_HELP",
    "0",
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "A",
    "B",
    "C",
    "D",
    "E",
    "F",
    "G",
    "H",
    "I",
    "J",
    "K",
    "L",
    "M",
    "N",
    "O",
    "P",
    "Q",
    "R",
    "S",
    "T",
    "U",
    "V",
    "W",
    "X",
    "Y",
    "Z",
    "VK_LWIN",
    "VK_RWIN",
    "VK_APPS",
    "Unknown",
    "VK_SLEEP",
    "VK_NUMPAD0",
    "VK_NUMPAD1",
    "VK_NUMPAD2",
    "VK_NUMPAD3",
    "VK_NUMPAD4",
    "VK_NUMPAD5",
    "VK_NUMPAD6",
    "VK_NUMPAD7",
    "VK_NUMPAD8",
    "VK_NUMPAD9",
    "VK_MULTIPLY",
    "VK_ADD",
    "VK_SEPARATOR",
    "VK_SUBTRACT",
    "VK_DECIMAL",
    "VK_DIVIDE",
    "VK_F1",
    "VK_F2",
    "VK_F3",
    "VK_F4",
    "VK_F5",
    "VK_F6",
    "VK_F7",
    "VK_F8",
    "VK_F9",
    "VK_F10",
    "VK_F11",
    "VK_F12",
    "VK_F13",
    "VK_F14",
    "VK_F15",
    "VK_F16",
    "VK_F17",
    "VK_F18",
    "VK_F19",
    "VK_F20",
    "VK_F21",
    "VK_F22",
    "VK_F23",
    "VK_F24",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "VK_NUMLOCK",
    "VK_SCROLL",
    "VK_OEM_NEC_EQUAL",
    "VK_OEM_FJ_MASSHOU",
    "VK_OEM_FJ_TOUROKU",
    "VK_OEM_FJ_LOYA",
    "VK_OEM_FJ_ROYA",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "VK_LSHIFT",
    "VK_RSHIFT",
    "VK_LCONTROL",
    "VK_RCONTROL",
    "VK_LMENU",
    "VK_RMENU"
};
static const char* KeyNames[] = {
    "Trigger Bot Key",
    "VK_LBUTTON",
    "VK_RBUTTON",
    "VK_CANCEL",
    "VK_MBUTTON",
    "VK_XBUTTON1",
    "VK_XBUTTON2",
    "Unknown",
    "VK_BACK",
    "VK_TAB",
    "Unknown",
    "Unknown",
    "VK_CLEAR",
    "VK_RETURN",
    "Unknown",
    "Unknown",
    "VK_SHIFT",
    "VK_CONTROL",
    "VK_MENU",
    "VK_PAUSE",
    "VK_CAPITAL",
    "VK_KANA",
    "Unknown",
    "VK_JUNJA",
    "VK_FINAL",
    "VK_KANJI",
    "Unknown",
    "VK_ESCAPE",
    "VK_CONVERT",
    "VK_NONCONVERT",
    "VK_ACCEPT",
    "VK_MODECHANGE",
    "VK_SPACE",
    "VK_PRIOR",
    "VK_NEXT",
    "VK_END",
    "VK_HOME",
    "VK_LEFT",
    "VK_UP",
    "VK_RIGHT",
    "VK_DOWN",
    "VK_SELECT",
    "VK_PRINT",
    "VK_EXECUTE",
    "VK_SNAPSHOT",
    "VK_INSERT",
    "VK_DELETE",
    "VK_HELP",
    "0",
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "A",
    "B",
    "C",
    "D",
    "E",
    "F",
    "G",
    "H",
    "I",
    "J",
    "K",
    "L",
    "M",
    "N",
    "O",
    "P",
    "Q",
    "R",
    "S",
    "T",
    "U",
    "V",
    "W",
    "X",
    "Y",
    "Z",
    "VK_LWIN",
    "VK_RWIN",
    "VK_APPS",
    "Unknown",
    "VK_SLEEP",
    "VK_NUMPAD0",
    "VK_NUMPAD1",
    "VK_NUMPAD2",
    "VK_NUMPAD3",
    "VK_NUMPAD4",
    "VK_NUMPAD5",
    "VK_NUMPAD6",
    "VK_NUMPAD7",
    "VK_NUMPAD8",
    "VK_NUMPAD9",
    "VK_MULTIPLY",
    "VK_ADD",
    "VK_SEPARATOR",
    "VK_SUBTRACT",
    "VK_DECIMAL",
    "VK_DIVIDE",
    "VK_F1",
    "VK_F2",
    "VK_F3",
    "VK_F4",
    "VK_F5",
    "VK_F6",
    "VK_F7",
    "VK_F8",
    "VK_F9",
    "VK_F10",
    "VK_F11",
    "VK_F12",
    "VK_F13",
    "VK_F14",
    "VK_F15",
    "VK_F16",
    "VK_F17",
    "VK_F18",
    "VK_F19",
    "VK_F20",
    "VK_F21",
    "VK_F22",
    "VK_F23",
    "VK_F24",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "VK_NUMLOCK",
    "VK_SCROLL",
    "VK_OEM_NEC_EQUAL",
    "VK_OEM_FJ_MASSHOU",
    "VK_OEM_FJ_TOUROKU",
    "VK_OEM_FJ_LOYA",
    "VK_OEM_FJ_ROYA",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "VK_LSHIFT",
    "VK_RSHIFT",
    "VK_LCONTROL",
    "VK_RCONTROL",
    "VK_LMENU",
    "VK_RMENU"
};
static const int KeyCodes[] = {
    0x0,  //Undefined
    0x01,
    0x02,
    0x03,
    0x04,
    0x05,
    0x06,
    0x07, //Undefined
    0x08,
    0x09,
    0x0A, //Reserved
    0x0B, //Reserved
    0x0C,
    0x0D,
    0x0E, //Undefined
    0x0F, //Undefined
    0x10,
    0x11,
    0x12,
    0x13,
    0x14,
    0x15,
    0x16, //IME On
    0x17,
    0x18,
    0x19,
    0x1A, //IME Off
    0x1B,
    0x1C,
    0x1D,
    0x1E,
    0x1F,
    0x20,
    0x21,
    0x22,
    0x23,
    0x24,
    0x25,
    0x26,
    0x27,
    0x28,
    0x29,
    0x2A,
    0x2B,
    0x2C,
    0x2D,
    0x2E,
    0x2F,
    0x30,
    0x31,
    0x32,
    0x33,
    0x34,
    0x35,
    0x36,
    0x37,
    0x38,
    0x39,
    0x3A, //Undefined
    0x3B, //Undefined
    0x3C, //Undefined
    0x3D, //Undefined
    0x3E, //Undefined
    0x3F, //Undefined
    0x40, //Undefined
    0x41,
    0x42,
    0x43,
    0x44,
    0x45,
    0x46,
    0x47,
    0x48,
    0x49,
    0x4A,
    0x4B,
    0x4C,
    0x4B,
    0x4E,
    0x4F,
    0x50,
    0x51,
    0x52,
    0x53,
    0x54,
    0x55,
    0x56,
    0x57,
    0x58,
    0x59,
    0x5A,
    0x5B,
    0x5C,
    0x5D,
    0x5E, //Rservered
    0x5F,
    0x60, //Numpad1
    0x61, //Numpad2
    0x62, //Numpad3
    0x63, //Numpad4
    0x64, //Numpad5
    0x65, //Numpad6
    0x66, //Numpad7
    0x67, //Numpad8
    0x68, //Numpad8
    0x69, //Numpad9
    0x6A,
    0x6B,
    0x6C,
    0x6D,
    0x6E,
    0x6F,
    0x70, //F1
    0x71, //F2
    0x72, //F3
    0x73, //F4
    0x74, //F5
    0x75, //F6
    0x76, //F7
    0x77, //F8
    0x78, //F9
    0x79, //F10
    0x7A, //F11
    0x7B, //F12
    0x7C, //F13
    0x7D, //F14
    0x7E, //F15
    0x7F, //F16
    0x80, //F17
    0x81, //F18
    0x82, //F19
    0x83, //F20
    0x84, //F21
    0x85, //F22
    0x86, //F23
    0x87, //F24
    0x88, //Unkown
    0x89, //Unkown
    0x8A, //Unkown
    0x8B, //Unkown
    0x8C, //Unkown
    0x8D, //Unkown
    0x8E, //Unkown
    0x8F, //Unkown
    0x90,
    0x91,
    0x92, //OEM Specific
    0x93, //OEM Specific
    0x94, //OEM Specific
    0x95, //OEM Specific
    0x96, //OEM Specific
    0x97, //Unkown
    0x98, //Unkown
    0x99, //Unkown
    0x9A, //Unkown
    0x9B, //Unkown
    0x9C, //Unkown
    0x9D, //Unkown
    0x9E, //Unkown 
    0x9F, //Unkown
    0xA0,
    0xA1,
    0xA2,
    0xA3,
    0xA4,
    0xA5
};

float BOG_TO_GRD(float BOG) {
    return (180 / M_PI) * BOG;
}

float GRD_TO_BOG(float GRD) {
    return (M_PI / 180) * GRD;
}
void HotKey(int* k, const ImVec2& size_arg = ImVec2(0, 0))
{
    static bool waitingforkey = false;
    if (waitingforkey == false) {
        if (ImGui::Button(KeyNames1[*(int*)k], size_arg))
            waitingforkey = true;
    }
    else if (waitingforkey == true) {
        ImGui::Button("...", size_arg);
        Sleep(50);
        for (auto& Key : KeyCodes)
        {
            if (GetAsyncKeyState_Spoofed(Key)) {
                *(int*)k = Key;
                waitingforkey = false;
            }
        }
    }
}
void HotKeytrig(int* k, const ImVec2& size_arg = ImVec2(0, 0))
{
    static bool waitingforkey = false;
    if (waitingforkey == false) {
        if (ImGui::Button(KeyNames[*(int*)k], size_arg))
            waitingforkey = true;
    }
    else if (waitingforkey == true) {
        ImGui::Button("...", size_arg);
        Sleep(50);
        for (auto& Key : KeyCodes)
        {
            if (GetAsyncKeyState_Spoofed(Key)) {
                *(int*)k = Key;
                waitingforkey = false;
            }
        }
    }
}




static int tab;
static int enemy_tab;

namespace Preview
{
    namespace box3d {
        float topleftfront_x = -72.f;
        float topleftfront_y = 82.f;

        float topleftback_x = -54.f;
        float topleftback_y = 61.f;

        float toprightfront_x = 61.f;
        float toprightfront_y = 82.f;

        float toprightback_x = 74.f;
        float toprightback_y = 61.f;

        float bottomleftfront_x = -85.f;
        float bottomleftfront_y = 335.f;

        float bottomleftback_x = -67.f;
        float bottomleftback_y = 305.f;

        float bottomrightfront_x = 49.f;
        float bottomrightfront_y = 342.f;

        float bottomrightback_x = 64.f;
        float bottomrightback_y = 312.f;
    }

    float head_bone_x = 0;
    float head_bone_y = 94;

    float neck_bone_x = 4;
    float neck_bone_y = 114;

    float chest_bone_x = 2;
    float chest_bone_y = 122;

    float left_shoulder_bone_x = -24;
    float left_shoulder_bone_y = 124;

    float left_elbow_bone_x = -37;
    float left_elbow_bone_y = 153;

    float left_hand_bone_x = -51;
    float left_hand_bone_y = 196;

    float right_hand_bone_x = 47;
    float right_hand_bone_y = 190;

    float right_elbow_bone_x = 43;
    float right_elbow_bone_y = 167;

    float right_shoulder_bone_x = 20;
    float right_shoulder_bone_y = 124;

    float pelvis_bone_x = -6;
    float pelvis_bone_y = 184;

    float left_thigh_bone_x = -22;
    float left_thigh_bone_y = 186;

    float right_thigh_bone_x = 12;
    float right_thigh_bone_y = 186;

    float right_knee_bone_x = 25;
    float right_knee_bone_y = 253;

    float left_knee_bone_x = -37;
    float left_knee_bone_y = 245;

    float right_foot_bone_x = 31;
    float right_foot_bone_y = 310;

    float left_foot_bone_x = -47;
    float left_foot_bone_y = 308;

    float right_footfinger_bone_x = 37;
    float right_footfinger_bone_y = 324;

    float left_footfinger_bone_x = -57;
    float left_footfinger_bone_y = 322;

}

LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);


inline void DrawFilledRect(int x, int y, int w, int h, ImU32 color, bool round = false)
{

    if (round)
        ImGui::GetForegroundDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), color, ImDrawCornerFlags_All, 30);
    else
        ImGui::GetForegroundDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), color, 0, 0);
}

inline void DrawRect(int x, int y, int w, int h, ImU32 color, bool round = false)
{

    if (round)
        ImGui::GetForegroundDrawList()->AddRect(ImVec2(x, y), ImVec2(x + w, y + h), color, ImDrawCornerFlags_All, 30);
    else
        ImGui::GetForegroundDrawList()->AddRect(ImVec2(x, y), ImVec2(x + w, y + h), color, 0, 0);
}


void RenderBox(bool ForeGround, float OffsetW, float OffsetH, int X, int Y, int W, int H, ImVec4 Color, int thickness, bool Filled, bool NoCorner) {
    float lineW = (W / OffsetW);
    float lineH = (H / OffsetH);
    ImDrawList* p = ImGui::GetBackgroundDrawList();
    if (ForeGround)
        p = ImGui::GetForegroundDrawList();

    if (Filled) {
        auto Converted = IM_COL32(Color.x * 255, Color.y * 255, Color.z * 255, 40);
        DrawFilledRect(ForeGround, X, Y, W, H, Converted);
    }
    if (NoCorner) {
        auto Converted = IM_COL32(Color.x * 255, Color.y * 255, Color.z * 255, Color.w * 255);
        DrawRect(ForeGround, X, Y, W, H, Converted);
    }
    else {
        //oben links nach unten
        p->AddLine(ImVec2(X, Y - 1), ImVec2(X, Y + lineH), ImGui::GetColorU32({ Color.x, Color.y, Color.z, Color.w }), thickness);

        //oben links nach rechts (l-mittig)
        p->AddLine(ImVec2(X, Y), ImVec2(X + lineW, Y), ImGui::GetColorU32({ Color.x, Color.y, Color.z, Color.w }), thickness);

        //oben rechts (r-mittig) nach rechts
        p->AddLine(ImVec2(X + W - lineW, Y), ImVec2(X + W + 2, Y), ImGui::GetColorU32({ Color.x, Color.y, Color.z, Color.w }), thickness);

        //oben rechts nach vert-rechts (oberhalb)
        p->AddLine(ImVec2(X + W, Y - 1), ImVec2(X + W, Y + lineH), ImGui::GetColorU32({ Color.x, Color.y, Color.z, Color.w }), thickness);

        //unten vert-links (unterhalb) nach unten links
        p->AddLine(ImVec2(X, Y + H - lineH), ImVec2(X, Y + H), ImGui::GetColorU32({ Color.x, Color.y, Color.z, Color.w }), thickness);

        //unten links nach rechts (mittig)
        p->AddLine(ImVec2(X - 1, Y + H), ImVec2(X + lineW + 1, Y + H), ImGui::GetColorU32({ Color.x, Color.y, Color.z, Color.w }), thickness);

        //unten rechts (mittig) nach rechts
        p->AddLine(ImVec2(X + W - lineW, Y + H), ImVec2(X + W + 2, Y + H), ImGui::GetColorU32({ Color.x, Color.y, Color.z, Color.w }), thickness);

        //unten rechts nach vert-rechts (unterhalb)
        p->AddLine(ImVec2(X + W, Y + H - lineH), ImVec2(X + W, Y + H), ImGui::GetColorU32({ Color.x, Color.y, Color.z, Color.w }), thickness);
    }
}



void RenderBox2(bool ForeGround, float OffsetW, float OffsetH, int X, int Y, int W, int H, ImVec4 Color, int thickness, bool Filled, bool NoCorner) {
    float lineW = (W / OffsetW);
    float lineH = (H / OffsetH);
    ImDrawList* p = ImGui::GetBackgroundDrawList();
    if (ForeGround)
        p = ImGui::GetForegroundDrawList();

    if (Filled) {
        auto Converted = IM_COL32(Color.x * 255, Color.y * 255, Color.z * 255, 40);
        DrawFilledRect(ForeGround, X, Y, W, H, Converted);
    }
    if (NoCorner) {
        auto Converted = IM_COL32(Color.x * 255, Color.y * 255, Color.z * 255, Color.w * 255);
        DrawRect(ForeGround, X, Y, W, H, Converted);
    }
    else {
        ImVec2 topLeft = ImVec2(X, Y);
        ImVec2 bottomRight = ImVec2(X + W, Y + H);

        // Calculate the radius for the rounded corners (adjust this value as needed)
        float cornerRadius = 5.0f;

        // Draw the rounded rectangle box
        p->AddRect(topLeft, bottomRight, ImGui::GetColorU32({ Color.x, Color.y, Color.z, Color.w }), cornerRadius, ImDrawCornerFlags_All, thickness);
    }
}

void RenderBox1(bool ForeGround, float OffsetW, float OffsetH, int X, int Y, int W, int H, ImVec4 Color, int thickness, bool Filled, bool NoCorner) {
    float lineW = (W / OffsetW);
    float lineH = (H / OffsetH);
    ImDrawList* p = ImGui::GetBackgroundDrawList();
    if (ForeGround)
        p = ImGui::GetForegroundDrawList();

    if (Filled) {
        auto Converted = IM_COL32(Color.x * 255, Color.y * 255, Color.z * 255, 40);
        DrawFilledRect(ForeGround, X, Y, W, H, Converted);
    }
    if (NoCorner) {
        auto Converted = IM_COL32(Color.x * 255, Color.y * 255, Color.z * 255, Color.w * 255);
        DrawRect(ForeGround, X, Y, W, H, Converted);
    }
    else {
        ImVec2 topLeft = ImVec2(X, Y);
        ImVec2 topRight = ImVec2(X + W, Y);
        ImVec2 bottomLeft = ImVec2(X, Y + H);
        ImVec2 bottomRight = ImVec2(X + W, Y + H);

        // Draw the lines to create the box
        p->AddLine(topLeft, topRight, ImGui::GetColorU32({ Color.x, Color.y, Color.z, Color.w }), thickness);
        p->AddLine(topRight, bottomRight, ImGui::GetColorU32({ Color.x, Color.y, Color.z, Color.w }), thickness);
        p->AddLine(bottomRight, bottomLeft, ImGui::GetColorU32({ Color.x, Color.y, Color.z, Color.w }), thickness);
        p->AddLine(bottomLeft, topLeft, ImGui::GetColorU32({ Color.x, Color.y, Color.z, Color.w }), thickness);
    }
}

void nuuh()
{
    if (tab == 0)
    {
        ImGui::SetCursorPos(ImVec2(78, 90));
        ImGui::MenuChild(E("tab 3"), ImVec2(280, 370));
        {

            ImGui::Checkbox(E("Aimbot"), &globals->aimbot);
            ImGui::Checkbox(E("Aim Prediction"), &globals->prediction);
            ImGui::Checkbox(E("Draw Fov "), &globals->render_field_of_view);

            ImGui::TextColored(ImColor(107, 107, 107), E("Aimbot Key"));

            HotKey(&globals->aimbot_key, ImVec2(280, 30));
        }
        ImGui::EndChild();
        ImGui::SetCursorPos(ImVec2(370, 90));
        ImGui::MenuChild(E("tab 4"), ImVec2(280, 370));
        {

            ImGui::SliderInt(E("Fov Amount"), &globals->field_of_view, 0, 500, E("%d%"));
            ImGui::SliderInt(E("Smoothing"), &globals->smooth, 0, 100, E("%d%"));
            ImGui::TextColored(ImColor(107, 107, 107), E("Extras"));

            ImGui::Checkbox(E("Target Line"), &globals->target_line);
            ImGui::Checkbox(E("Target Text"), &globals->target_text);
            ImGui::TextColored(ImColor(107, 107, 107), E("Trigger Bot"));

            ImGui::Checkbox(E("Trigger Bot Shotgun Only"), &globals->triggerbot);
            ImGui::SliderInt(E("Trigger Bot Max Distance"), &globals->maximum_distance, 0, 50, E("%d%"));
            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.64f, 0.64f, 0.64f, 1.0f));
            ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0.41f, 0.41f, 0.41f, 1.0f));
            if (Cheat_shi.star)
            {
                HotKeytrig(&globals->triggerbot_key, ImVec2(280, 30));
            }

        }
        ImGui::EndChild();
    }
}
int weapontab = 1;
void configs()
{

    ImGui::SetCursorPos(ImVec2(78, 90));
    ImGui::MenuChild(E("tab 3"), ImVec2(280, 370));
    {

        ImGui::TextColored(ImColor(107, 107, 107), E("Thickness"));
        ImGui::SliderInt(E("Skeleton Thickness"), &globals->skeleton_thick, 0, 10, E("%d%"));
        ImGui::SliderInt(E("Box Thickness"), &globals->box_thick, 0, 10, E("%d%"));
        ImGui::TextColored(ImColor(107, 107, 107), E("Font"));

        ImGui::SliderInt(E("Font Size"), &globals->font_size, 0, 30, E("%d%"));
        ImGui::Checkbox(E("Text Outline"), &globals->text_outline);


    }
    ImGui::EndChild();
    ImGui::SetCursorPos(ImVec2(370, 90));
    ImGui::MenuChild(E("tab 4"), ImVec2(280, 370));
    {




    }
    ImGui::EndChild();



}
void weapons()
{
    if (tab == 3)
    {
        ImGui::SetCursorPos(ImVec2(78, 90));
        ImGui::MenuChild(E("tab 3"), ImVec2(570, 40));
        {
            if (ImGui::Button("Rifle", ImVec2(137, 25)))
            {
                weapontab = 1;
            }
            ImGui::SameLine();
            if (ImGui::Button("Shotgun", ImVec2(137, 25)))
            {
                weapontab = 2;
            }
            ImGui::SameLine();
            if (ImGui::Button("Smg", ImVec2(137, 25)))
            {
                weapontab = 3;
            }
            ImGui::SameLine();
            if (ImGui::Button("Sniper", ImVec2(133, 25)))
            {
                weapontab = 4;
            }
        }
        ImGui::EndChild();

        ImGui::SetCursorPos(ImVec2(78, 140));
        ImGui::MenuChild(E("tab 9"), ImVec2(450, 320));
        {
            if (weapontab == 1)
            {
                ImGui::Text(E("Assault Rifle"));

                ImGui::Checkbox(E("Rifle Render Fov"), &rifle::render_fov);

                ImGui::SliderFloat(E("Rifle Smooth"), &rifle::smooth, 1, 30);

                ImGui::SliderFloat(E("Rifle Fov"), &rifle::aim_fov, 1, 300);



            }
            if (weapontab == 2)
            {
                ImGui::Text(E("Shotgun"));
                ImGui::Separator();
                ImGui::Checkbox(E("Shotgun Render Fov"), &shotgun::render_fov);
                ImGui::SliderFloat(E("Shotgun Smooth"), &shotgun::smooth, 1, 30);

                ImGui::SliderFloat(E("Shotgun Fov"), &shotgun::aim_fov, 1, 300);


            }
            else if (weapontab == 3)
            {
                ImGui::Text(E("Smg"));
                ImGui::Separator();
                ImGui::Checkbox(E("Smg Render Fov"), &smg::render_fov);

                ImGui::SliderFloat(E("Smg Smooth"), &smg::smooth, 1, 30);
                ImGui::SliderFloat(E("Smg Fov"), &smg::aim_fov, 1, 300);

            }
            else if (weapontab == 4)
            {
                ImGui::Text(E("Sniper"));
                ImGui::Separator();
                ImGui::Checkbox(E("Sniper Render Fov"), &sniper::render_fov);



                ImGui::SliderFloat(E("Sniper Smooth"), &sniper::smooth, 1, 30);
                ImGui::SliderFloat(E("Sniper Fov"), &sniper::aim_fov, 1, 3000);


            }
        }
        ImGui::EndChild();



    }
}
void Misc()
{
    if (tab == 2)
    {
        ImGui::SetCursorPos(ImVec2(78, 90));
        ImGui::MenuChild(E("tab 3"), ImVec2(280, 370));
        {
            ImGui::Checkbox(E("Enable Weapon Configs"), &globals->weapon_cfg);
            ImGui::Checkbox(E("Outlined Esp"), &globals->outline);

            

            
            if (ImGui::Button("Save Config", ImVec2(250, 50)))
            {
                SaveConfig();
            }
            if (ImGui::Button("Load Config", ImVec2(250, 50)))
            {
                LoadConfig();
            }




        }
        ImGui::EndChild();
        ImGui::SetCursorPos(ImVec2(370, 90));
        ImGui::MenuChild(E("tab 7"), ImVec2(280, 370));
        {
            ImGui::GetWindowDrawList()->AddRectFilled(ImVec2(p.x + 365, p.y + 84), ImVec2(p.x + 641, p.y + 439), ImColor(23, 25, 24), 5);
            ImGui::GetWindowDrawList()->AddRect(ImVec2(p.x + 365, p.y + 84), ImVec2(p.x + 641, p.y + 439), ImColor(32, 35, 34), 5, 15, 1.5);
            ImGui::Text((" "));
            ImGui::ColorEdit3((E(" Fov Color")), PlayerColor::accentcolor);

            ImGui::Text((E(" Visible player")));
            ImGui::ColorEdit3((E(" Box")), PlayerColor::BoxVisible);
            ImGui::ColorEdit3((E(" Skeleton")), PlayerColor::SkeletonVisible);
            ImGui::ColorEdit3((E(" Top text")), PlayerColor::TopTextVisible);
            ImGui::ColorEdit3((E(" Bottom text")), PlayerColor::BottomTextVisible);

            ImGui::Text((E(" Not visible player")));
            ImGui::ColorEdit3((E(" Box ")), PlayerColor::BoxNotVisible);
            ImGui::ColorEdit3((E(" Skeleton ")), PlayerColor::SkeletonNotVisible);
            ImGui::ColorEdit3((E(" Top text ")), PlayerColor::TopTextNotVisible);
            ImGui::ColorEdit3((E(" Bottom text ")), PlayerColor::BottomTextNotVisible);
        }
        ImGui::EndChild();
    }
}
void legit()
{


    if (tab == 1)
    {
        ImGui::SetCursorPos(ImVec2(78, 88));
        ImGui::MenuChild(E("tab 1"), ImVec2(280, 370));
        {
            ImGui::Spacing();

            if (ImGui::Checkbox(E("2D box "), &globals->bounding_box))
            {
                globals->Cornerbox = false;
            }
            if (ImGui::Checkbox(E("Corner Box "), &globals->Cornerbox))
            {
                globals->bounding_box = false;
            }
            ImGui::Checkbox(E("Skeleton "), &globals->skeletons);
            ImGui::Checkbox(E("Head Esp "), &globals->head);
            ImGui::Checkbox(E("Weapon Esp "), &globals->weapon_esp);
            ImGui::Checkbox(E("Distance Esp "), &globals->distance);
        }
        ImGui::EndChild();
        ImGui::GetWindowDrawList()->AddRectFilled(ImVec2(p.x + 365, p.y + 84), ImVec2(p.x + 641, p.y + 439), ImColor(23, 25, 24), 5);//bg 2
        ImGui::GetWindowDrawList()->AddRect(ImVec2(p.x + 365, p.y + 84), ImVec2(p.x + 641, p.y + 439), ImColor(32, 35, 34), 5, 15, 1.5);//rect
        ImGui::SetCursorPos(ImVec2(405, 130));

        if (globals->skeletons && !globals->head)
        {
            ImGui::Image(skeleton, ImVec2(190, 280));
        }
        else if (globals->head && !globals->skeletons)
        {
            ImGui::Image(head, ImVec2(190, 280));
        }
        else if (globals->head || globals->skeletons)
        {
            ImGui::Image(headskel, ImVec2(190, 280));
        }
        else
        {
            ImGui::Image(normal, ImVec2(190, 280));
        }

        ImDrawList* draw_list = ImGui::GetForegroundDrawList();
        ImVec2 test = ImGui::GetWindowPos();

        ImGui::SetCursorPos(ImVec2(240, 80));
        if (globals->bounding_box) {
            ImGui::SetCursorPos(ImVec2(405, 105));
            draw_list->AddRect(ImVec2(test.x + 405, test.y + 120), ImVec2(test.x + 605, test.y + 415), ImColor(255, 255, 255));
        }
        if (globals->Cornerbox)
        {
            ImGui::SetCursorPos(ImVec2(405, 105));
            draw_list->AddLine(ImVec2(test.x + 405, test.y + 120), ImVec2(test.x + 425, test.y + 120), ImColor(255, 255, 255));
            draw_list->AddLine(ImVec2(test.x + 405, test.y + 120), ImVec2(test.x + 405, test.y + 140), ImColor(255, 255, 255));
            draw_list->AddLine(ImVec2(test.x + 605, test.y + 120), ImVec2(test.x + 585, test.y + 120), ImColor(255, 255, 255));
            draw_list->AddLine(ImVec2(test.x + 605, test.y + 120), ImVec2(test.x + 605, test.y + 140), ImColor(255, 255, 255));
            draw_list->AddLine(ImVec2(test.x + 405, test.y + 415), ImVec2(test.x + 425, test.y + 415), ImColor(255, 255, 255));
            draw_list->AddLine(ImVec2(test.x + 405, test.y + 415), ImVec2(test.x + 405, test.y + 395), ImColor(255, 255, 255));
            draw_list->AddLine(ImVec2(test.x + 605, test.y + 415), ImVec2(test.x + 585, test.y + 415), ImColor(255, 255, 255));
            draw_list->AddLine(ImVec2(test.x + 605, test.y + 415), ImVec2(test.x + 605, test.y + 395), ImColor(255, 255, 255));
        }
        int ThisOffset = -3;
        int ThisOffset2 = -19;
        int ThisOffset1 = 23;
        if (globals->distance) {

            ImGui::SetCursorPos(ImVec2(405, 105));
            ImVec2 test1 = ImGui::GetWindowPos();
            float bottomMiddleX = (test.x + 405 + test.x + 565) / 2.0f;
            float bottomMiddleY = test.y + 415;
            draw_list->AddText(ImVec2(bottomMiddleX, bottomMiddleY), ImColor(255, 255, 255), E("100m"));
        }
        if (globals->weapon_esp) {

            ImGui::SetCursorPos(ImVec2(405, 105));
            ImVec2 test1 = ImGui::GetWindowPos();
            float bottomMiddleX = (test.x + 405 + test.x + 540) / 2.0f;
            float bottomMiddleY = test.y + 430;
            draw_list->AddText(ImVec2(bottomMiddleX, bottomMiddleY), ImColor(255, 255, 255), E("[Pickaxe]"));
        }

        if (globals->username) {
            ImGui::SetCursorPos(ImVec2(405, 105));
            ImVec2 test1 = ImGui::GetWindowPos();
            float bottomMiddleX = (test.x + 405 + test.x + 555) / 2.0f;
            float bottomMiddleY = test.y + 110;
            std::string text1 = Cheat_shi.Cheat_name;

            draw_list->AddText(ImVec2(bottomMiddleX, bottomMiddleY), ImColor(255, 255, 255), text1.c_str());
        }
    }
}

void render_sub()
{
    ImGui::SetCursorPos(ImVec2(90, 30));
    

    if (tab == 0)
    {
        ImGui::GetWindowDrawList()->AddText(TestFont, 35, ImVec2(p.x + 135, p.y + 25), ImColor(107, 107, 107), "Aimbot");//name tab
        ImGui::GetWindowDrawList()->AddText(IconFont, 25, ImVec2(p.x + 90, p.y + 29), ImColor(107, 107, 107), "A");//icon

    }

    if (tab == 1)
    {
        ImGui::GetWindowDrawList()->AddText(TestFont, 35, ImVec2(p.x + 135, p.y + 25), ImColor(107, 107, 107), "Visuals");//name tab
        ImGui::GetWindowDrawList()->AddText(IconFont, 25, ImVec2(p.x + 90, p.y + 29), ImColor(107, 107, 107), "B");//icon
    }

    if (tab == 2)
    {
        ImGui::GetWindowDrawList()->AddText(TestFont, 35, ImVec2(p.x + 135, p.y + 25), ImColor(107, 107, 107), "Settings");//name tab
        ImGui::GetWindowDrawList()->AddText(IconFont, 25, ImVec2(p.x + 90, p.y + 29), ImColor(107, 107, 107), "F");//icon
    }
    if (tab == 3)
    {
        ImGui::GetWindowDrawList()->AddText(TestFont, 35, ImVec2(p.x + 135, p.y + 25), ImColor(107, 107, 107), "Weapons");//name tab
        ImGui::GetWindowDrawList()->AddText(IconFont, 25, ImVec2(p.x + 90, p.y + 29), ImColor(107, 107, 107), "C");//icon


    }
    if (tab == 4)
    {
        ImGui::GetWindowDrawList()->AddText(TestFont, 35, ImVec2(p.x + 135, p.y + 25), ImColor(107, 107, 107), "Extra");//name tab
        ImGui::GetWindowDrawList()->AddText(IconFont, 25, ImVec2(p.x + 90, p.y + 29), ImColor(107, 107, 107), "D");//icon


    }
}

void render_tab()
{
    ImGui::PushFont(IconFont);
    {
        ImGui::SetCursorPos(ImVec2{ 26, 90 });
        if (ImGui::tab("A", !tab)) tab = 0;

        ImGui::SetCursorPos(ImVec2{ 26, 136 });
        if (ImGui::tab("B", tab == 1)) tab = 1;


        ImGui::SetCursorPos(ImVec2{ 26, 182 });
        if (ImGui::tab("F", tab == 2)) tab = 2;

        ImGui::SetCursorPos(ImVec2{ 26, 228 });
        if (ImGui::tab("C", tab == 3)) tab = 3;

        ImGui::SetCursorPos(ImVec2{ 26, 274 });
        if (ImGui::tab("D", tab == 4)) tab = 4;




    }
    ImGui::PopFont();

    switch (tab)
    {
    case 0:     nuuh();       break;
    case 1:     legit();       break;
    case 2:     Misc();       break;
    case 3:     weapons();       break;
    case 4:     configs();       break;

    }
}



namespace render {
    class c_render {
    public:
        auto Setup() -> RENDER_INFORMATION {
            if (!render::c_render::hijack()) return RENDER_HIJACK_FAILED;

            if (!render::c_render::ImGui()) return RENDER_IMGUI_FAILED;

            return RENDER_SETUP_SUCCESSFUL;
        }

        auto Render() -> bool {
            static RECT rect_og;
            MSG msg = { NULL };
            ZeroMemory(&msg, sizeof(MSG));

            while (msg.message != WM_QUIT)
            {
                UpdateWindow_Spoofed(window_handle);
                ShowWindow_Spoofed(window_handle, SW_SHOW);

                if ((PeekMessageA_Spoofed)(&msg, window_handle, 0, 0, PM_REMOVE))
                {
                    TranslateMessage(&msg);
                    DispatchMessage(&msg);
                }

                ImGuiIO& io = ImGui::GetIO();
                io.ImeWindowHandle = window_handle;
                io.DeltaTime = 1.0f / 60.0f;

                POINT p_cursor;
                GetCursorPos(&p_cursor);
                io.MousePos.x = p_cursor.x;
                io.MousePos.y = p_cursor.y;

                if (GetAsyncKeyState_Spoofed(VK_LBUTTON)) {
                    io.MouseDown[0] = true;
                    io.MouseClicked[0] = true;
                    io.MouseClickedPos[0].x = io.MousePos.x;
                    io.MouseClickedPos[0].x = io.MousePos.y;
                }
                else
                    io.MouseDown[0] = false;


                render::c_render::Draw();
            }
            ImGui_ImplDX11_Shutdown();
            ImGui_ImplWin32_Shutdown();
            ImGui::DestroyContext();

            (DestroyWindow)(window_handle);

            return true;
        }



        auto ImGui() -> bool {


            DXGI_SWAP_CHAIN_DESC swap_chain_description = {};
            swap_chain_description.BufferCount = 2;
            swap_chain_description.BufferDesc.Width = 0; // Set the appropriate width based on your requirements
            swap_chain_description.BufferDesc.Height = 0; // Set the appropriate height based on your requirements
            swap_chain_description.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
            swap_chain_description.BufferDesc.RefreshRate.Numerator = 60;
            swap_chain_description.BufferDesc.RefreshRate.Denominator = 1;
            swap_chain_description.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
            swap_chain_description.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
            swap_chain_description.OutputWindow = window_handle;
            swap_chain_description.SampleDesc.Count = 1;
            swap_chain_description.SampleDesc.Quality = 0;
            swap_chain_description.Windowed = TRUE;
            swap_chain_description.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

            D3D_FEATURE_LEVEL d3d_feature_lvl;

            const D3D_FEATURE_LEVEL d3d_feature_array[1] = { D3D_FEATURE_LEVEL_11_0 };

            D3D11CreateDeviceAndSwapChain(
                nullptr,
                D3D_DRIVER_TYPE_HARDWARE,
                nullptr,
                0,
                d3d_feature_array,
                1,
                D3D11_SDK_VERSION,
                &swap_chain_description,
                &d3d_swap_chain,
                &d3d_device,
                &d3d_feature_lvl,
                &d3d_device_ctx);

            ID3D11Texture2D* pBackBuffer;

            d3d_swap_chain->GetBuffer(0, IID_PPV_ARGS(&pBackBuffer));

            d3d_device->CreateRenderTargetView(pBackBuffer, NULL, &d3d_render_target);


            pBackBuffer->Release();

            IMGUI_CHECKVERSION();

            ImGui::CreateContext();

            ImGuiIO& io = ImGui::GetIO();

            io.IniFilename = NULL;

            (void)io;
            D3DX11_IMAGE_LOAD_INFO info;
            ID3DX11ThreadPump* pump{ nullptr };

            if (Cheat_shi.star)
            {
                D3DX11CreateShaderResourceViewFromMemory(d3d_device, Logos, sizeof(Logos), &info, pump, &logo, 0);
            }
            else if (Cheat_shi.orbit)
            {
                D3DX11CreateShaderResourceViewFromMemory(d3d_device, Logos1, sizeof(Logos1), &info, pump, &logo, 0);
            }
            
            D3DX11CreateShaderResourceViewFromMemory(d3d_device, gingerbread, sizeof(gingerbread), &info, pump, &normal, 0);
            D3DX11CreateShaderResourceViewFromMemory(d3d_device, gingerskel, sizeof(gingerskel), &info, pump, &skeleton, 0);
            D3DX11CreateShaderResourceViewFromMemory(d3d_device, gingerhead, sizeof(gingerhead), &info, pump, &head, 0);
            D3DX11CreateShaderResourceViewFromMemory(d3d_device, headskels, sizeof(headskels), &info, pump, &headskel, 0);
            D3DX11CreateShaderResourceViewFromMemory(d3d_device, circles, sizeof(circles), &info, pump, &circle, 0);

            io.Fonts->AddFontFromMemoryTTF(burbank, sizeof(burbank), 14.0f);
            IconFont = io.Fonts->AddFontFromMemoryTTF(Icons, sizeof(Icons), 23, NULL, io.Fonts->GetGlyphRangesCyrillic());
            IconFontLogs = io.Fonts->AddFontFromMemoryTTF(IconFontLog, sizeof(IconFontLog), 25, NULL, io.Fonts->GetGlyphRangesCyrillic());
            LexendDecaFont = io.Fonts->AddFontFromMemoryTTF(LexendDeca, sizeof(LexendDeca), 22, NULL, io.Fonts->GetGlyphRangesCyrillic());
            InterMedium = io.Fonts->AddFontFromMemoryTTF(Intermedium, sizeof(Intermedium), 17, NULL, io.Fonts->GetGlyphRangesCyrillic());
            TestFont = io.Fonts->AddFontFromMemoryTTF(Intermedium, sizeof(Intermedium), 40, NULL, io.Fonts->GetGlyphRangesCyrillic());

            InterMediumone = io.Fonts->AddFontFromMemoryTTF(Intermedium, sizeof(Intermedium), 14, NULL, io.Fonts->GetGlyphRangesCyrillic());

            io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\Inkfree.TTF", 16.f);
            


            ImGui_ImplWin32_Init(window_handle);

            ImGui_ImplDX11_Init(d3d_device, d3d_device_ctx);

            d3d_device->Release();

            return true;

        }

        DWORD FindProcessId(const char* ProcessName)
        {
            PROCESSENTRY32 processInfo;
            processInfo.dwSize = sizeof(processInfo);

            HANDLE processesSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
            if (processesSnapshot == INVALID_HANDLE_VALUE)
                return 0;

            Process32First(processesSnapshot, &processInfo);
            if (!strcmp(processInfo.szExeFile, ProcessName))
            {
                CloseHandle_Spoofed(processesSnapshot);
                return processInfo.th32ProcessID;
            }

            while (Process32Next(processesSnapshot, &processInfo))
            {
                if (!strcmp(processInfo.szExeFile, ProcessName))
                {
                    CloseHandle_Spoofed(processesSnapshot);
                    return processInfo.th32ProcessID;
                }
            }

            CloseHandle_Spoofed(processesSnapshot);
            return 0;
        }

        static HWND get_gdi_window(int dwProcessID)
        {
            HWND hCurWnd = nullptr;
            while (true)
            {
                hCurWnd = FindWindowEx(nullptr, hCurWnd, nullptr, nullptr);
                DWORD checkProcessID;
                GetWindowThreadProcessId(hCurWnd, &checkProcessID);
                if (checkProcessID == dwProcessID)
                {
                    char className[256];
                    GetClassNameA(hCurWnd, className, 256);
                    if (strstr(className, "GDI+ Hook Window Class"))
                        return hCurWnd;
                }
            }
        }

        auto hijack() -> bool {
            window_handle = FindWindowA_Spoofed(E("MedalOverlayClass"), E("MedalOverlay"));

            if (!window_handle)
            {
                MessageBoxA(0, skCrypt("Medal Not Found"), skCrypt("Storm"), MB_ICONINFORMATION);
            }

            int WindowWidth = GetSystemMetrics(SM_CXSCREEN);
            int WindowHeight = GetSystemMetrics(SM_CYSCREEN);


          
            if (!SetWindowPos_Spoofed(window_handle, HWND_TOPMOST, 0, 0, WindowWidth, WindowHeight, SWP_SHOWWINDOW))
            {
                return false;
            }

            if (!SetLayeredWindowAttributes_Spoofed(window_handle, RGB(0, 0, 0), 255, LWA_ALPHA))
            {
                return false;
            }


            if (!SetWindowLongA_Spoofed(window_handle, GWL_EXSTYLE, GetWindowLong(window_handle, GWL_EXSTYLE) | WS_EX_TRANSPARENT))
            {
                return false;
            }

            MARGINS Margin = { -1 };
            if (FAILED(DwmExtendFrameIntoClientArea(window_handle, &Margin)))
            {
                return false;
            }

            ShowWindow_Spoofed(window_handle, SW_SHOW);

            UpdateWindow_Spoofed(window_handle);

            ShowWindow_Spoofed(window_handle, SW_HIDE);

            return true;
        }

        auto Menu() -> void {



            ImGui::SetNextWindowSize(ImVec2(gs));
            if (ImGui::Begin((E("")), nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoScrollbar))
            {
                s = ImVec2(ImGui::GetWindowSize().x - ImGui::GetStyle().WindowPadding.x * 2, ImGui::GetWindowSize().y - ImGui::GetStyle().WindowPadding.y * 2);
                p = ImVec2(ImGui::GetWindowPos().x + ImGui::GetStyle().WindowPadding.x, ImGui::GetWindowPos().y + ImGui::GetStyle().WindowPadding.y);

                ImGui::GetWindowDrawList()->AddRectFilled(ImVec2(p.x, p.y), ImVec2(p.x + 650, p.y + 450), ImColor(15, 17, 16), 10); //bg

                ImGui::GetWindowDrawList()->AddRectFilled(ImVec2(p.x + 10, p.y + 10), ImVec2(p.x + 60, p.y + 440), ImColor(23, 25, 24), 5);//bg 1
                ImGui::GetWindowDrawList()->AddRect(ImVec2(p.x + 10, p.y + 10), ImVec2(p.x + 60, p.y + 440), ImColor(32, 35, 34), 5, 15, 1.5);//rect

                ImGui::GetWindowDrawList()->AddRectFilled(ImVec2(p.x + 71, p.y + 10), ImVec2(p.x + 641, p.y + 78), ImColor(23, 25, 24), 5);//bg 2
                ImGui::GetWindowDrawList()->AddRect(ImVec2(p.x + 71, p.y + 10), ImVec2(p.x + 641, p.y + 78), ImColor(32, 35, 34), 5, 15, 1.5);//rect

                
                if (Cheat_shi.star)
                {


                    {
                        render_sub();
                        render_tab();

                    }
                }

                

            }
            ImGui::End();
        }




        auto Draw() -> void {

            ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 0.f);

            ImGui_ImplDX11_NewFrame();
            ImGui_ImplWin32_NewFrame();
            ImGui::NewFrame();

            if (GetAsyncKeyState_Spoofed(VK_INSERT) & 1)
                globals->render_menu = !globals->render_menu;

            if (globals->render_field_of_view) {

                if (globals->normal_fov)
                {
                    if (globals->outline)
                    {
                        ImGui::GetForegroundDrawList()->AddCircle(ImVec2(globals->width / 2, globals->height / 2), globals->field_of_view, ImColor(0, 0, 0), 64, 2.5);
                        ImGui::GetForegroundDrawList()->AddCircle(ImVec2(globals->width / 2, globals->height / 2), globals->field_of_view, ImColor(PlayerColor::accentcolor[0], PlayerColor::accentcolor[1], PlayerColor::accentcolor[2], 1.0f), 64, 1);

                    }
                    else
                    {
                        ImGui::GetForegroundDrawList()->AddCircle(ImVec2(globals->width / 2, globals->height / 2), globals->field_of_view, ImColor(PlayerColor::accentcolor[0], PlayerColor::accentcolor[1], PlayerColor::accentcolor[2], 1.0f), 64, 1);
                    }
                }
                if (globals->star_fov)
                {

                    ImColor fov_col;
                    fov_col = ImVec4(PlayerColor::accentcolor[0], PlayerColor::accentcolor[1], PlayerColor::accentcolor[2], 1.0f);

                    float size = globals->field_of_view;
                    ImVec2 center(globals->width / 2, globals->height / 2);

                    ImVec2 starPoints[10];
                    float angleOff = 144.0f;

                    for (int i = 0; i < 5; i++) {
                        starPoints[i * 2] = ImVec2(center.x + size * sin(angleOff * i * 3.14159265359 / 180.0f),
                            center.y - size * cos(angleOff * i * 3.14159265359 / 180.0f));
                        starPoints[i * 2 + 1] = ImVec2(center.x + size / 2 * sin(angleOff * (i * 2 + 1) * 3.14159265359 / 180.0f),
                            center.y - size / 2 * cos(angleOff * (i * 2 + 1) * 3.14159265359 / 180.0f));
                    }

                    for (int i = 0; i < 5; i++) {
                        int next = (i + 1) % 5;
                        ImGui::GetBackgroundDrawList()->AddLine(starPoints[i * 2], starPoints[next * 2], fov_col, 2);

                    }

                }
                if (globals->chrome_fov)
                {

                    ImColor fov_col;
                    fov_col = ImVec4(PlayerColor::accentcolor[0], PlayerColor::accentcolor[1], PlayerColor::accentcolor[2], 1.0f);

                    float size = globals->field_of_view;
                    ImVec2 center(globals->width / 2, globals->height / 2);

                    // Draw a star
                    ImVec2 starPoints[10];
                    float angleOff = 36.0f;

                    for (int i = 0; i < 5; i++) {
                        starPoints[i * 2] = ImVec2(center.x + size * sin(angleOff * i * 2 * 3.14159265359 / 180.0f),
                            center.y + size * cos(angleOff * i * 2 * 3.14159265359 / 180.0f));
                        starPoints[i * 2 + 1] = ImVec2(center.x + size / 2 * sin(angleOff * (i * 2 + 1) * 3.14159265359 / 180.0f),
                            center.y + size / 2 * cos(angleOff * (i * 2 + 1) * 3.14159265359 / 180.0f));
                    }

                    for (int i = 0; i < 5; i++) {
                        int next = (i + 1) % 5;
                        ImGui::GetBackgroundDrawList()->AddLine(starPoints[i * 2], starPoints[next * 2], fov_col, 2);
                        ImGui::GetBackgroundDrawList()->AddLine(starPoints[i * 2], starPoints[next * 2 + 1], fov_col, 2);
                        ImGui::GetBackgroundDrawList()->AddLine(starPoints[i * 2 + 1], starPoints[next * 2 + 1], fov_col, 2);
                    }

                }
                if (globals->dick_fov)
                {




                    ImColor rocket_col;
                    rocket_col = ImVec4(PlayerColor::accentcolor[0], PlayerColor::accentcolor[1], PlayerColor::accentcolor[2], 1.0f); // Red color, you can adjust this

                    float size = globals->field_of_view;  // Adjust the size as needed
                    float cylinderWidth = 60.0f;  // Adjust the width of the cylinder
                    ImVec2 center(globals->width / 2, globals->height / 2);

                    // Draw two circles on the bottom
                    ImGui::GetBackgroundDrawList()->AddCircle(ImVec2(center.x - size / 2, center.y), size / 2, rocket_col, 20);
                    ImGui::GetBackgroundDrawList()->AddCircle(ImVec2(center.x + size / 2, center.y), size / 2, rocket_col, 20);

                    // Draw a cylinder-like shape in the middle
                    ImVec2 cylinderTopLeft(center.x - cylinderWidth / 2, center.y - size / 2 * 5);
                    ImVec2 cylinderBottomRight(center.x + cylinderWidth / 2, center.y + size / 2 - 40);
                    ImGui::GetBackgroundDrawList()->AddRect(cylinderTopLeft, cylinderBottomRight, rocket_col, 0, 15);

                    // Draw a rounded top for the cylinder
                    float radius = cylinderWidth / 2;
                    ImVec2 cylinderTopCenter(center.x, center.y - size / 2 * 5);
                    ImGui::GetBackgroundDrawList()->AddCircle(cylinderTopCenter, radius, rocket_col, 20, 2);






                }
                if (globals->triangle_fov)
                {
                    ImColor rocket_col;
                    rocket_col = ImVec4(PlayerColor::accentcolor[0], PlayerColor::accentcolor[1], PlayerColor::accentcolor[2], 1.0f); // Red color, you can adjust this

                    float size = globals->field_of_view;
                    ImVec2 center(globals->width / 2, globals->height / 2);

                    ImVec2 bottomLeft(center.x - size, center.y + size);
                    ImVec2 bottomRight(center.x + size, center.y + size);
                    ImVec2 top(center.x, center.y - size);

                    ImGui::GetBackgroundDrawList()->AddTriangle(bottomLeft, bottomRight, top, rocket_col, 2);
                }

                if (globals->naze_fov)
                {
                    ImColor rocket_col;
                    rocket_col = ImVec4(PlayerColor::accentcolor[0], PlayerColor::accentcolor[1], PlayerColor::accentcolor[2], 1.0f); // Red color, you can adjust this
                    POINT Screen;
                    int oodofdfo, jbjfdbdsf;
                    Screen.x = GetSystemMetrics(0);
                    Screen.y = GetSystemMetrics(1);
                    // Middle POINT
                    POINT Middle;
                    Middle.x = (int)(Screen.x / 2);
                    Middle.y = (int)(Screen.y / 2);
                    int a = (int)(Screen.y / 2 / 30);
                    float gamma = atan(a / a);
                    static int faken_rot = 0;
                    faken_rot++;
                    int Drehungswinkel = faken_rot;

                    int i = 0;
                    while (i < 4)
                    {
                        std::vector<int> p;
                        p.push_back(a * sin(GRD_TO_BOG(Drehungswinkel + (i * 90))));                                    // p[0]        p0_A.x
                        p.push_back(a * cos(GRD_TO_BOG(Drehungswinkel + (i * 90))));                                    // p[1]        p0_A.y
                        p.push_back((a / cos(gamma)) * sin(GRD_TO_BOG(Drehungswinkel + (i * 90) + BOG_TO_GRD(gamma))));    // p[2]        p0_B.x
                        p.push_back((a / cos(gamma)) * cos(GRD_TO_BOG(Drehungswinkel + (i * 90) + BOG_TO_GRD(gamma))));    // p[3]        p0_B.y

                        // Calculate the hue based on time (you can replace this with any other variable)
                        float hue = fmodf(ImGui::GetTime(), 1.0f); // Range from 0.0 to 1.0

                        ImVec2 p0 = ImVec2(Middle.x, Middle.y);
                        ImVec2 p1 = ImVec2(Middle.x + p[0], Middle.y - p[1]);
                        ImVec2 p2 = ImVec2(Middle.x + p[2], Middle.y - p[3]);

                        ImGui::GetBackgroundDrawList()->AddLine(p0, p1, rocket_col);
                        ImGui::GetBackgroundDrawList()->AddLine(p1, p2, rocket_col);

                        i++;
                    }
                }
            }

            Game->ActorLoop();
            //   Game->LevelDrawing();


            std::string text1 = Cheat_shi.Cheat_name;
            std::string text2 = Cheat_shi.Cheat_Version;
            std::string text3 = Cheat_shi.Cheat_name + " Storm Public " + Cheat_shi.Cheat_Version;


            ImGui::GetForegroundDrawList()->AddText(ImVec2(20, 20), ImColor(1.f, 1.f, 1.f), text3.c_str());
            if (globals->render_menu)
            {

                Menu();

            }


            

            ImGui::Render();
            const float clear_color_with_alpha[4] = { clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w };
            d3d_device_ctx->OMSetRenderTargets(1, &d3d_render_target, nullptr);
            d3d_device_ctx->ClearRenderTargetView(d3d_render_target, clear_color_with_alpha);
            ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

            d3d_swap_chain->Present(1, 0);

        }
    };
} static render::c_render* Render = new render::c_render();