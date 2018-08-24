#include <pistache/http.h>
#include <pistache/router.h>
#include <pistache/endpoint.h>
#include <pistache/serializer/rapidjson.h>
#include <memory>
#include <string>
#include "drumgizmo.h"

using namespace Pistache;
char levels_json[] = 
"\
{                                   \
    \"levels\": [                   \
        {                           \
            \"name\": \"Snare\",    \
            \"level\": 50           \
        },                          \
        {                           \
            \"name\": \"Hi-hat\",   \
            \"level\": 60           \
        }                           \
    ]                               \
}";


class DrumRestService {
public:
    DrumRestService(Address addr) : m_endpoint(std::make_shared<Http::Endpoint>(addr)) {
    }

    void init() {
        //auto opts = Http::Endpoint::options().threads(1).flags(Tcp::Options::InstallSignalHandler);
        auto opts = Http::Endpoint::options().threads(1);
        m_endpoint->init(opts);
    }

    void start() {
        Rest::Routes::Get(m_router, "/kit/all", Rest::Routes::bind(&DrumRestService::getAllKits, this));
        Rest::Routes::Get(m_router, "/kit/:id", Rest::Routes::bind(&DrumRestService::getKit, this));
        Rest::Routes::Get(m_router, "/levels", Rest::Routes::bind(&DrumRestService::getLevels, this));
        m_endpoint->setHandler(m_router.handler());
        m_endpoint->serve();
    }

    void shutdown() {
        m_endpoint->shutdown();
    }

protected:
    void getAllKits(const Rest::Request& request, Http::ResponseWriter response) {
        response.send(Pistache::Http::Code::Ok, "Get all kits");
    }

    void getKit(const Rest::Request& request, Http::ResponseWriter response) {
        auto id = request.param(":id").as<std::string>();
        response.send(Pistache::Http::Code::Ok, std::string("Get kit: ") + id);
    }

    void getLevels(const Rest::Request& request, Http::ResponseWriter response) {
        response.setMime(MIME(Application, Json));
        response.send(Pistache::Http::Code::Ok, levels_json);
    }

private:
    std::shared_ptr<Http::Endpoint>     m_endpoint;
    Rest::Router                        m_router;
};

int main() {
    Port    port(9080);
    Address addr(Ipv4::any(), port);

    DrumRestService service(addr);
    service.init();
    service.start();

    service.shutdown();

    return 0;
}
