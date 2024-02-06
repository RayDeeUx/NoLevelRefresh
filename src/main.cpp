#include <Geode/Geode.hpp>
#include <Geode/modify/LevelInfoLayer.hpp>

using namespace geode::prelude;

class $modify(LevelInfoLayer) {
	bool init (GJGameLevel* p0, bool p1) {
		if (!LevelInfoLayer::init(p0, p1)) return false;
		if (!Loader::get()->isModLoaded("geode.node-ids")) return true; // in case someone decides to get cheeky with .geode files
		if (!Loader::get()->isModLoaded("thesillydoggo.moretags")) return true; // avoid running the function if mod isnt found
		if (!Mod::get()->getSettingValue<bool>("hideRefreshButton")) return true;
		getChildByIDRecursive("right-side-menu")->getChildByIDRecursive("refresh-button")->setScale(0);
		return true;
	}
};
