// checksum 0xd721 version 0x9000c
/*
  This file was generated by the Html5 Application wizard of Qt Creator.
  Html5ApplicationViewer is a convenience class containing mobile device specific
  code such as screen orientation handling.
  It is recommended not to modify this file, since newer versions of Qt Creator
  may offer an updated version of it.
*/

#ifndef HTML5APPLICATIONVIEWER_H
#define HTML5APPLICATIONVIEWER_H

#include <QWidget>
#include <QUrl>
#include "view_iface.h"
#ifndef Q_MOC_RUN
#include "daemon_backend.h"
#endif

class QGraphicsWebView;

class Html5ApplicationViewer : public QWidget, public view::i_view
{
    Q_OBJECT

public:
    enum ScreenOrientation {
        ScreenOrientationLockPortrait,
        ScreenOrientationLockLandscape,
        ScreenOrientationAuto
    };

    explicit Html5ApplicationViewer(QWidget *parent = 0);
    virtual ~Html5ApplicationViewer();

    void loadFile(const QString &fileName);
    void loadUrl(const QUrl &url);

    // Note that this will only have an effect on Fremantle.
    void setOrientation(ScreenOrientation orientation);

    void showExpanded();

    QGraphicsWebView *webView() const;
    bool start_backend(int argc, char* argv[]);
protected:

private slots:
    bool do_close();
    bool on_request_quit();
public slots:
    void open_wallet();

private:
    void closeEvent(QCloseEvent *event);


    //------- i_view ---------
    virtual bool update_daemon_status(const view::daemon_status_info& info);
    virtual bool on_backend_stopped();
    virtual bool show_msg_box(const std::string& message);
    virtual bool update_wallet_status(const view::wallet_status_info& wsi);
    virtual bool update_wallet_info(const view::wallet_info& wsi);
    virtual bool money_receive(const view::transfer_event_info& tei);
    virtual bool money_spent(const view::transfer_event_info& tei);
    virtual bool show_wallet();

    class Html5ApplicationViewerPrivate *m_d;
    daemon_backend m_backend;
    std::atomic<bool> m_quit_requested;
    std::atomic<bool> m_deinitialize_done;
};

#endif // HTML5APPLICATIONVIEWER_H