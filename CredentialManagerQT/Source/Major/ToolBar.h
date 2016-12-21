﻿#ifndef _bnb_Tool_Bar_H_
#define _bnb_Tool_Bar_H_

QT_BEGIN_NAMESPACE

class ToolBar : public QWidget
{
    struct ui_type
    {
        QLineEdit* m_editPath;
        QPushButton* m_btnNew;
        QPushButton* m_btnOpen;
        QPushButton* m_btnAbout;

        void SetupUI(QWidget* pView);
        void RetranslateUI(QWidget* pView);
    };

public:

    ToolBar(DelegateMainView* pDelegate = nullptr, QWidget * parent = nullptr);

    const ui_type& UI() const { return (_ui); }

    void UpdatePath(const QString& strPath);

private:

    void OnClickedNew();
    void OnClickedOpen();
    void OnClickedAbout();

private:

    ui_type _ui;

    DelegateMainView* _delegate;

};

QT_END_NAMESPACE

#endif // !_bnb_Tool_Bar_H_
