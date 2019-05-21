//
// Created by Ervin Bosenbacher on 2019-05-20.
//

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <quickfix/Application.h>
#include <quickfix/Message.h>
#include <quickfix/Initiator.h>
#include <quickfix/SessionID.h>
#include <quickfix/SocketInitiator.h>
#include <quickfix/SessionSettings.h>
#include <quickfix/Log.h>
#include <quickfix/FileLog.h>
#include <quickfix/MessageStore.h>
#include <quickfix/FileStore.h>

namespace py = pybind11;

int add(int i, int j) {
    return i + j;
}

//void init_ex1(py::module &m) {
//    m.def("add", [](int a, int b) { return a + b; });
//}
class PyApplication : public FIX::Application {
public:
    /* Inherit the constructors */
    using FIX::Application::Application;

    /// Notification of a session begin created
    void onCreate(const FIX::SessionID& sessionID) override {
        PYBIND11_OVERLOAD_PURE(
                void, /* Return type */
                FIX::Application,      /* Parent class */
                onCreate,          /* Name of function in C++ (must match Python name) */
                sessionID      /* Argument(s) */
        );
    }

    /// Notification of a session successfully logging on
    void onLogon(const FIX::SessionID& sessionID) override {
        PYBIND11_OVERLOAD_PURE(
                void, /* Return type */
                FIX::Application,      /* Parent class */
                onLogon,          /* Name of function in C++ (must match Python name) */
                sessionID      /* Argument(s) */
        );
    }

    /// Notification of a session logging off or disconnecting
    void onLogout(const FIX::SessionID& sessionID) override {
        PYBIND11_OVERLOAD_PURE(
                void, /* Return type */
                FIX::Application,      /* Parent class */
                onLogout,          /* Name of function in C++ (must match Python name) */
                sessionID      /* Argument(s) */
        );
    }

    /// Notification of admin message being sent to target
    void toAdmin(FIX::Message& message, const FIX::SessionID& sessionID) override {
        PYBIND11_OVERLOAD_PURE(
                void, /* Return type */
                FIX::Application,      /* Parent class */
                toAdmin,          /* Name of function in C++ (must match Python name) */
                message, sessionID      /* Argument(s) */
        );
    }

    /// Notification of app message being sent to target
    void toApp(FIX::Message& message, const FIX::SessionID& sessionID) override {
        PYBIND11_OVERLOAD_PURE(
                void, /* Return type */
                FIX::Application,      /* Parent class */
                toApp,          /* Name of function in C++ (must match Python name) */
                message, sessionID      /* Argument(s) */
        );
    }

    /// Notification of admin message being received from target
    void fromAdmin(const FIX::Message& message, const FIX::SessionID& sessionID) override {
        PYBIND11_OVERLOAD_PURE(
                void, /* Return type */
                FIX::Application,      /* Parent class */
                fromAdmin,          /* Name of function in C++ (must match Python name) */
                message, sessionID      /* Argument(s) */
        );
    }

    /// Notification of app message being received from target
    void fromApp(const FIX::Message& message, const FIX::SessionID& sessionID) override {
        PYBIND11_OVERLOAD_PURE(
                void, /* Return type */
                FIX::Application,      /* Parent class */
                fromApp,          /* Name of function in C++ (must match Python name) */
                message, sessionID      /* Argument(s) */
        );
    }
};


PYBIND11_MODULE(pyfix, m) {

py::class_<FIX::Message> _message(m, "Message");
_message
    .def(py::init<>())
    .def(py::init<std::vector<int>, std::vector<int>, std::vector<int>>())
    .def("toXML", (std::string (FIX::Message::*)() const) &FIX::Message::toXML)
    .def("setField", (void (FIX::Message::*)(int, const std::string&)) &FIX::Message::setField);


py::class_<FIX::Application, PyApplication> _application(m, "Application");
_application
    .def(py::init<>())
    .def("onCreate", &FIX::Application::onCreate)
    .def("onLogon", &FIX::Application::onLogon)
    .def("onLogout", &FIX::Application::onLogout)
    .def("toAdmin", &FIX::Application::toAdmin)
    .def("toApp", &FIX::Application::toApp)
    .def("fromAdmin", &FIX::Application::fromAdmin)
    .def("fromApp", &FIX::Application::fromApp);


// SessionSettings
py::class_<FIX::SessionSettings> _session_settings(m, "SessionSettings");
_session_settings
    .def(py::init<const std::string&>());


// FileStoreFactory
py::class_<FIX::FileStoreFactory> _file_store_factory(m, "FileStoreFactory");
_file_store_factory
    .def(py::init<const FIX::SessionSettings&>());


// FileLogFactory
py::class_<FIX::FileLogFactory> _file_log_factory(m, "FileLogFactory");
_file_log_factory
    .def(py::init<const FIX::SessionSettings&>());


// ScreenLogFactory
py::class_<FIX::ScreenLogFactory> _screen_log_factory(m, "ScreenLogFactory");
_screen_log_factory
    .def(py::init<const FIX::SessionSettings&>());


// SocketInitiator
py::class_<FIX::SocketInitiator> _socket_initiator(m, "SocketInitiator");
_socket_initiator
    .def(py::init<FIX::Application&, FIX::MessageStoreFactory&, const FIX::SessionSettings&, FIX::LogFactory&>())
    .def("start", &FIX::SocketInitiator::start);


m.def("add", &add, "A function which adds two numbers");
}