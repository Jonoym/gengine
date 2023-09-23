# Todo List

1. Animation Controller - start playing animations
- Add offsets to the positions
- Clean code and diagram

Fix the animation controller to allow for force and priority of animations

2. UI interaction and Overlays
- UI displayed on the screen, need to add priorities

3. Mouse Input


        std::unordered_map<std::string, std::vector<std::function<void(std::string *)>>> eventListeners;

        eventListeners.emplace("helo", std::vector<std::function<void(std::string *)>>{});
        eventListeners.find("helo")->second.push_back([this](std::string* message) {
            test(message);
        });