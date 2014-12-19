/*
RustyCoder

Copyright (C) 2012-2014 Chak Wai Yuan

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef GUI_PROFILE_FORM_H
#define GUI_PROFILE_FORM_H

#include "file_extension_filters.h"

class ProfileForm : public EventHandlerInterface
{
    private:
        class CmbBxEncoderEvents;
        class ProfileReportListViewEvents;
        class CmbBxOptionsSetterEvents;
        class BtnSetOptionEvents;
        class BtnOpenEvents;
        class BtnSaveEvents;
        class BtnSaveAsEvents;
        class BtnLoadDefaultEvents;

        HINSTANCE hInstance = nullptr;

        HWND hWndParent;

        bool form_loaded = false;
        bool form_deleting = false;

        std::unique_ptr<ProfileForm> *me;
        std::unique_ptr<Window> window;
        std::unique_ptr<Label> lbl_encoder_sign;
        std::unique_ptr<ComboBox> cmbbx_encoder;
        std::unique_ptr<CmbBxEncoderEvents> cmbbx_encoder_events;
        std::unique_ptr<Button> btn_load_default;
        std::unique_ptr<BtnLoadDefaultEvents> btn_load_default_events;
        std::unique_ptr<ReportListView> profile_report_list_view;
        std::unique_ptr<ProfileReportListViewEvents> profile_report_list_view_events;
        std::unique_ptr<Label> lbl_option_value_sign;
        std::unique_ptr<ComboBox> cmbbx_options_setter;
        std::unique_ptr<CmbBxOptionsSetterEvents> cmbbx_options_setter_events;
        std::unique_ptr<SingleLineTextBox> sltxtbx_options_setter;
        std::unique_ptr<Button> btn_set_option;
        std::unique_ptr<BtnSetOptionEvents> btn_set_option_events;
        std::unique_ptr<Button> btn_open;
        std::unique_ptr<BtnOpenEvents> btn_open_events;
        std::unique_ptr<Button> btn_save;
        std::unique_ptr<BtnSaveEvents> btn_save_events;
        std::unique_ptr<Button> btn_save_as;
        std::unique_ptr<BtnSaveAsEvents> btn_save_as_events;

        void OnCreate(HWND hWnd);

    public:
        ProfileForm(const ProfileForm &) = delete;
        ProfileForm & operator=(const ProfileForm &) = delete;

        ProfileForm(HINSTANCE hInstance, HWND hWndParent, std::unique_ptr<ProfileForm> &me);

        virtual LRESULT HandleEvent(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

        ~ProfileForm();
};

class ProfileForm::CmbBxEncoderEvents
{
    private:
        ProfileForm * const profile_form = nullptr;

    public:
        CmbBxEncoderEvents(const CmbBxEncoderEvents &) = delete;
        CmbBxEncoderEvents & operator=(const CmbBxEncoderEvents &) = delete;

        CmbBxEncoderEvents(ProfileForm * const profile_form);

        bool IsSelectedEncoder(void);
        Encoder<void>::ID GetSelectedEncoderID(void);
};

class ProfileForm::ProfileReportListViewEvents
{
    friend class ProfileForm;

    private:
        ProfileForm *profile_form = nullptr;

        bool profile_has_unsaved_changes = false;
        bool loaded_encoder_profile = false;
        bool has_old_loaded_encoder_profile_id = false;
        bool setter_control_created = false;

        unsigned int style_change_count = 0u;

        Encoder<void>::ID old_loaded_encoder_profile_id;
        Encoder<void>::ID loaded_encoder_profile_id;

        std::wstring current_profile_last_saved_full_path;

        std::unique_ptr<EncoderOptions> encoder_options;

        void PopulateListView(Encoder<void>::ID encoder_id, EncoderOptions *encoder_options = nullptr);

        void OnItemChanged(NMLISTVIEW *list_view_notification_message);
        void OnDeleteAllItems(void);

    public:
        ProfileReportListViewEvents(const ProfileReportListViewEvents &) = delete;
        ProfileReportListViewEvents & operator=(const ProfileReportListViewEvents &) = delete;

        ProfileReportListViewEvents(ProfileForm * const profile_form);

        bool IsEncoderProfileLoaded(void);
        bool HasUnsavedProfileChanges(void);

        std::wstring GetCurrentProfileLastSavedFullPath(void);

        Encoder<void>::ID GetLoadedProfileEncoderID(void);

        void SaveProfile(std::wstring profile_full_path);

        void LoadProfile(HWND hWnd);
        void LoadDefaultProfile(Encoder<void>::ID encoder_id);

        void SetEncoderOption(std::string &value);
};

class ProfileForm::CmbBxOptionsSetterEvents
{
    friend class ProfileForm;

    private:
        ProfileForm *profile_form = nullptr;

        void OnSelectionOk(void);

    public:
        CmbBxOptionsSetterEvents(const CmbBxOptionsSetterEvents &) = delete;
        CmbBxOptionsSetterEvents & operator=(const CmbBxOptionsSetterEvents &) = delete;

        CmbBxOptionsSetterEvents(ProfileForm * const profile_form) : profile_form(profile_form) {}
};

class ProfileForm::BtnSetOptionEvents
{
    friend class ProfileForm;

    private:
        ProfileForm * const profile_form = nullptr;

        void OnClick(HWND hWnd);

    public:
        BtnSetOptionEvents(const BtnSetOptionEvents &) = delete;
        BtnSetOptionEvents & operator=(const BtnSetOptionEvents &) = delete;

        BtnSetOptionEvents(ProfileForm * const profile_form) : profile_form(profile_form) {}
};

class ProfileForm::BtnOpenEvents
{
    friend class ProfileForm;

    private:
        ProfileForm * const profile_form = nullptr;

        void OnClick(HWND hWnd);

    public:
        BtnOpenEvents(const BtnOpenEvents &) = delete;
        BtnOpenEvents & operator=(const BtnOpenEvents &) = delete;

        BtnOpenEvents(ProfileForm * const profile_form) : profile_form(profile_form) {}
};

class ProfileForm::BtnSaveEvents
{
    friend class ProfileForm;

    private:
        ProfileForm * const profile_form = nullptr;

        void OnClick(void);

    public:
        BtnSaveEvents(const BtnSaveEvents &) = delete;
        BtnSaveEvents & operator=(const BtnSaveEvents &) = delete;

        BtnSaveEvents(ProfileForm * const profile_form) : profile_form(profile_form) {}
};

class ProfileForm::BtnSaveAsEvents
{
    friend class ProfileForm;

    private:
        ProfileForm * const profile_form = nullptr;

        void OnClick(HWND hWnd);

    public:
        BtnSaveAsEvents(const BtnSaveAsEvents &) = delete;
        BtnSaveAsEvents & operator=(const BtnSaveAsEvents &) = delete;

        BtnSaveAsEvents(ProfileForm * const profile_form) : profile_form(profile_form) {}
};

class ProfileForm::BtnLoadDefaultEvents
{
    friend class ProfileForm;

    private:
        ProfileForm * const profile_form = nullptr;

        void OnClick(void);

    public:
        BtnLoadDefaultEvents(const BtnLoadDefaultEvents &) = delete;
        BtnLoadDefaultEvents & operator=(const BtnLoadDefaultEvents &) = delete;

        BtnLoadDefaultEvents(ProfileForm * const profile_form) : profile_form(profile_form) {}
};

#endif