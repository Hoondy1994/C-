#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <string>

// 接口类：监听器
class WeatherListener {
public:
    virtual void onWeatherUpdate(const std::string& weather) = 0;
    virtual ~WeatherListener() = default;
};

// 天气广播站
class WeatherStation {
public:
    void addListener(std::shared_ptr<WeatherListener> listener) {
        listeners_.emplace_back(listener);  // 存 weak，不增加引用计数
    }

    void notifyWeatherChanged(const std::string& weather) {
        std::cout << "[Station] Weather changed to: " << weather << "\n";

        // 遍历所有监听器
        for (auto it = listeners_.begin(); it != listeners_.end(); ) {
            if (auto listener = it->lock()) {  // 转换成 shared_ptr 判断是否有效
                listener->onWeatherUpdate(weather);
                ++it;
            }
            else {
                // 已被销毁，移除
                it = listeners_.erase(it);
            }
        }
    }

private:
    std::vector<std::weak_ptr<WeatherListener>> listeners_;
};

// 用户：小红
class XiaoHong : public WeatherListener {
public:
    void onWeatherUpdate(const std::string& weather) override {
        std::cout << "小红收到天气变化通知: " << weather << "\n";
    }
};

// 用户：小明
class XiaoMing : public WeatherListener {
public:
    void onWeatherUpdate(const std::string& weather) override {
        std::cout << "小明收到天气变化通知: " << weather << "\n";
    }
};

int main() {
    WeatherStation station;

    auto hong = std::make_shared<XiaoHong>();
    auto ming = std::make_shared<XiaoMing>();

    station.addListener(hong);
    station.addListener(ming);

    station.notifyWeatherChanged("Sunny ☀️");

    // 小红退出监听
    hong.reset();  // 删除对象

    station.notifyWeatherChanged("Rainy 🌧️");

    return 0;
}
