//
// Created by Ervin Bosenbacher on 2019-05-20.
//

// pybind
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

// quickfix stuff
#include <quickfix/Application.h>
#include <quickfix/Message.h>
#include <quickfix/Initiator.h>
#include <quickfix/SessionID.h>
#include <quickfix/SocketInitiator.h>
#include <quickfix/MessageCracker.h>
#include <quickfix/SessionSettings.h>
#include <quickfix/Log.h>
#include <quickfix/FileLog.h>
#include <quickfix/MessageStore.h>
#include <quickfix/FileStore.h>

#include <quickfix/fix44/Message.h>


// std stuff
#include <memory>
#include <functional>

namespace py = pybind11;

int add(int i, int j) {
    return i + j;
}

//void init_ex1(py::module &m) {
//    m.def("add", [](int a, int b) { return a + b; });
//}

namespace QuickFix {

    class Application
            : public FIX::Application
            , public FIX::MessageCracker {

    public:
        Application() {}

        /// Notification of a session begin created
        void onCreate(const FIX::SessionID& sessionID) {
            if (_funcOnCreate) {
                _funcOnCreate(sessionID);
            }
        }

        /// Notification of a session successfully logging on
        void onLogon( const FIX::SessionID& sessionID) {
            if (_funcOnLogon) {
                _funcOnLogon(sessionID);
            }
        }

        /// Notification of a session logging off or disconnecting
        void onLogout( const FIX::SessionID& ) { }
        /// Notification of admin message being sent to target
        void toAdmin( FIX::Message&, const FIX::SessionID& ) {}
        /// Notification of app message being sent to target
        void toApp( FIX::Message&, const FIX::SessionID& ) {}
        /// Notification of admin message being received from target
        void fromAdmin( const FIX::Message&, const FIX::SessionID& ) {}
        /// Notification of app message being received from target
        void fromApp( const FIX::Message& message, const FIX::SessionID& sessionID) {
            crack(message, sessionID);
        }

        // cracked stuff
        void onMessage(const FIX44::Heartbeat& msg, const FIX::SessionID& sid) {
            if (_funcOnMessageHeartbeat) {
                _funcOnMessageHeartbeat(msg, sid);
            }
        }

        void onMessage(const FIX44::TestRequest& msg, const FIX::SessionID& sid) {
            if (_funcOnMessageTestRequest) {
                _funcOnMessageTestRequest(msg, sid);
            }
        }

        virtual void onMessage(const FIX44::ResendRequest& msg, const FIX::SessionID& sid) {
            if (_funcOnMessageResendRequest) {
                _funcOnMessageResendRequest(msg, sid);
            }
        }
        /*
        virtual void onMessage( const Reject&, const FIX::SessionID& )
        {}
        virtual void onMessage( const SequenceReset&, const FIX::SessionID& )
        {}
        virtual void onMessage( const Logout&, const FIX::SessionID& )
        {}
        virtual void onMessage( const IOI&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const Advertisement&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const ExecutionReport&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const OrderCancelReject&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const Logon&, const FIX::SessionID& )
        {}
        virtual void onMessage( const News&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const Email&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const NewOrderSingle&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const NewOrderList&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const OrderCancelRequest&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const OrderCancelReplaceRequest&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const OrderStatusRequest&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const AllocationInstruction&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const ListCancelRequest&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const ListExecute&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const ListStatusRequest&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const ListStatus&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const AllocationInstructionAck&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const DontKnowTrade&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const QuoteRequest&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const Quote&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const SettlementInstructions&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const MarketDataRequest&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const MarketDataSnapshotFullRefresh&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const MarketDataIncrementalRefresh&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const MarketDataRequestReject&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const QuoteCancel&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const QuoteStatusRequest&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const MassQuoteAcknowledgement&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const SecurityDefinitionRequest&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const SecurityDefinition&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const SecurityStatusRequest&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const SecurityStatus&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const TradingSessionStatusRequest&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const TradingSessionStatus&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const MassQuote&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const BusinessMessageReject&, const FIX::SessionID& )
        {}
        virtual void onMessage( const BidRequest&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const BidResponse&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const ListStrikePrice&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const XMLnonFIX&, const FIX::SessionID& )
        {}
        virtual void onMessage( const RegistrationInstructions&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const RegistrationInstructionsResponse&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const OrderMassCancelRequest&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const OrderMassCancelReport&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const NewOrderCross&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const CrossOrderCancelReplaceRequest&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const CrossOrderCancelRequest&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const SecurityTypeRequest&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const SecurityTypes&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const SecurityListRequest&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const SecurityList&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const DerivativeSecurityListRequest&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const DerivativeSecurityList&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const NewOrderMultileg&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const MultilegOrderCancelReplace&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const TradeCaptureReportRequest&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const TradeCaptureReport&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const OrderMassStatusRequest&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const QuoteRequestReject&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const RFQRequest&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const QuoteStatusReport&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const QuoteResponse&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const Confirmation&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const PositionMaintenanceRequest&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const PositionMaintenanceReport&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const RequestForPositions&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const RequestForPositionsAck&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const PositionReport&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const TradeCaptureReportRequestAck&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const TradeCaptureReportAck&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const AllocationReport&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const AllocationReportAck&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const ConfirmationAck&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const SettlementInstructionRequest&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const AssignmentReport&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const CollateralRequest&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const CollateralAssignment&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const CollateralResponse&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const CollateralReport&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const CollateralInquiry&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const NetworkCounterpartySystemStatusRequest&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const NetworkCounterpartySystemStatusResponse&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const UserRequest&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const UserResponse&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const CollateralInquiryAck&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        virtual void onMessage( const ConfirmationRequest&, const FIX::SessionID& )
        { throw FIX::UnsupportedMessageType(); }
        */

    public:
        void setOnCreate(const std::function<void(const FIX::SessionID&)> &funcOnCreate) {
            _funcOnCreate = funcOnCreate;
        }

        void setOnLogon(const std::function<void(const FIX::SessionID&)> &funcOnLogon) {
            _funcOnLogon = funcOnLogon;
        }

    private:
        std::function<void(const FIX::SessionID&)> _funcOnCreate;
        std::function<void(const FIX::SessionID&)> _funcOnLogon;
        std::function<void(const FIX::SessionID&)> _funcOnLogout;
        std::function<void(const FIX::Message&, const FIX::SessionID&)> _funcToAdmin;
        std::function<void(const FIX::Message&, const FIX::SessionID&)> _funcToApp;
        std::function<void(const FIX::Message&, const FIX::SessionID&)> _funcFromAdmin;
        std::function<void(const FIX::Message&, const FIX::SessionID&)> _funcFromApp;


        std::function<void(const FIX44::Heartbeat& msg, const FIX::SessionID& sid)> _funcOnMessageHeartbeat;
        std::function<void(const FIX44::TestRequest&, const FIX::SessionID&)> _funcOnMessageTestRequest;
        std::function<void(const FIX44::ResendRequest& msg, const FIX::SessionID& sid)> _funcOnMessageResendRequest;

    };

    class Initiator {
    public:
        Initiator(QuickFix::Application& application, FIX::MessageStoreFactory& messageStoreFactory,
                const FIX::SessionSettings& sessionSettings, FIX::LogFactory &logFactory)
                : _initiator(application, messageStoreFactory, sessionSettings, logFactory)
        {}
        void start() {
            _initiator.start();
        }

    private:
        FIX::SocketInitiator _initiator;
    };
} // quickfix namespace


PYBIND11_MODULE(pyfix, m) {

py::class_<FIX::Message> _message(m, "Message");
_message
    .def(py::init<>())
    .def(py::init<std::vector<int>, std::vector<int>, std::vector<int>>())
    .def("toXML", (std::string (FIX::Message::*)() const) &FIX::Message::toXML)
    .def("setField", (void (FIX::Message::*)(int, const std::string&)) &FIX::Message::setField);

py::class_<QuickFix::Application> _application(m, "Application");
_application
    .def(py::init<>())
    .def("setOnCreate", &QuickFix::Application::setOnCreate)
    .def("setOnLogon", &QuickFix::Application::setOnLogon);

py::class_<QuickFix::Initiator> _initiator(m, "Initiatior");
_initiator
    .def(py::init<QuickFix::Application&, FIX::MessageStoreFactory&, const FIX::SessionSettings&, FIX::LogFactory&>())
    .def("start", &QuickFix::Initiator::start);


// SessionSettings
py::class_<FIX::SessionSettings> _session_settings(m, "SessionSettings");
_session_settings
    .def(py::init<const std::string&>());

//SessionID
py::class_<FIX::SessionID> _session_id(m, "SessionID");
_session_id
    .def(py::init<>())
    .def("toString", (std::string (FIX::SessionID::*)() const) &FIX::SessionID::toString);

//MessageStoreFactory
py::class_<FIX::MessageStoreFactory>(m, "MessageStoreFactory");

// FileStoreFactory
py::class_<FIX::FileStoreFactory, FIX::MessageStoreFactory> _file_store_factory(m, "FileStoreFactory");
_file_store_factory
    .def(py::init<const FIX::SessionSettings&>());

// LogFactory
py::class_<FIX::LogFactory> _log_factory(m, "LogFactory");

// FileLogFactory
py::class_<FIX::FileLogFactory, FIX::LogFactory> _file_log_factory(m, "FileLogFactory");
_file_log_factory
    .def(py::init<const FIX::SessionSettings&>());


// ScreenLogFactory
py::class_<FIX::ScreenLogFactory, FIX::LogFactory> _screen_log_factory(m, "ScreenLogFactory");
_screen_log_factory
    .def(py::init<const FIX::SessionSettings&>());


// SocketInitiator
py::class_<FIX::SocketInitiator> _socket_initiator(m, "SocketInitiator");
_socket_initiator
    .def(py::init<FIX::Application&, FIX::MessageStoreFactory&, const FIX::SessionSettings&, FIX::LogFactory&>())
    .def("start", &FIX::SocketInitiator::start);


m.def("add", &add, "A function which adds two numbers");
}