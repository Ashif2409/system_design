/*
Observer Design Pattern:

The **Observer Design Pattern** defines a one-to-many dependency between objects so that
when one object (Subject) changes state, all its dependent objects (Observers) are notified
and updated automatically.

✅ Useful when multiple objects need to be notified of changes in a central object.

─────────────         subscribes        ┌──────────────┐
│   Channel   │ <---------------------- │ Subscriber 1 │
│  (Subject)  │ --------------------->  │ Subscriber 2 │
─────────────         notify()         └──────────────┘

*/

#include <bits/stdc++.h>
using namespace std;

// Forward declaration
class ISubscriber;

// Subject Interface
class IChannel {
public:
    virtual void subscribe(ISubscriber* subscriber) = 0;
    virtual void unsubscribe(ISubscriber* subscriber) = 0;
    virtual void notify() = 0;
    virtual ~IChannel() {}
};

// Observer Interface
class ISubscriber {
public:
    virtual void update() = 0;
    virtual ~ISubscriber() {}
};

// Concrete Subject (Channel)
class Channel : public IChannel {
private:
    vector<ISubscriber*> subscribers;
    string channelName;
    string latestVideo;

public:
    Channel(string name) : channelName(name) {}

    void subscribe(ISubscriber* subscriber) override {
        for (auto sub : subscribers) {
            if (sub == subscriber) {
                cout << "Subscriber already exists in channel: " << channelName << endl;
                return;
            }
        }
        subscribers.push_back(subscriber);
        cout << "Subscriber added to channel: " << channelName << endl;
    }

    void unsubscribe(ISubscriber* subscriber) override {
        auto it = find(subscribers.begin(), subscribers.end(), subscriber);
        if (it != subscribers.end()) {
            subscribers.erase(it);
            cout << "Subscriber removed from channel: " << channelName << endl;
        } else {
            cout << "Subscriber not found in channel: " << channelName << endl;
        }
    }

    void notify() override {
        cout << "Notifying subscribers of channel: " << channelName << endl;
        for (auto sub : subscribers) {
            sub->update();
        }
    }

    void uploadVideo() {
        cout << "New video \"" << latestVideo << "\" uploaded to channel: " << channelName << endl;
        notify();
    }

    void setVideo(string videoTitle) {
        latestVideo = videoTitle;
    }
};

// Concrete Observer (Subscriber)
class Subscriber : public ISubscriber {
private:
    string subscriberName;
    Channel* subscribedChannel;

public:
    Subscriber(string name, Channel* channel) {
        this->subscriberName = name;
        this->subscribedChannel = channel;
    }

    void update() override {
        cout << "Subscriber " << subscriberName << " has been notified of new content!" << endl;
    }
};

// Main function to test the pattern
int main() {
    Channel* myChannel = new Channel("Tech Insights");

    Subscriber* sub1 = new Subscriber("Alice", myChannel);
    Subscriber* sub2 = new Subscriber("Bob", myChannel);

    myChannel->subscribe(sub1);
    myChannel->subscribe(sub2);

    myChannel->setVideo("Observer Design Pattern Explained");
    myChannel->uploadVideo();

    myChannel->unsubscribe(sub1);

    myChannel->setVideo("Understanding Dependency Injection");
    myChannel->uploadVideo();

    delete sub1;
    delete sub2;
    delete myChannel;

    return 0;
}
