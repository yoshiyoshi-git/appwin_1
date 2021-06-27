#pragma once

#include "MainPage.g.h"
#include "StringViewModel.h"

#include "winrt/Windows.UI.WindowManagement.h"
#include "winrt/Windows.UI.Xaml.Hosting.h"
#include "BlankPage1.h"

extern winrt::appwin_1::StringViewModel* pmain_string;

namespace winrt::appwin_1::implementation
{
    struct MainPage : MainPageT<MainPage>
    {
        MainPage();
        appwin_1::StringViewModel MainString();

        Windows::UI::WindowManagement::AppWindow blank1Window{ nullptr };
        Windows::UI::Xaml::Controls::Frame blank1Frame{};
        void OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs const& e);

        //GetMainCurrentをSetMainTextの追加
        static appwin_1::MainPage GetMainCurrent() { return maincurrent; }
        void SetMainText(hstring const& data);

    private:
        appwin_1::StringViewModel m_mainString{ nullptr };

        //maincurrentの追加
        static appwin_1::MainPage maincurrent;

    public:
        winrt::Windows::Foundation::IAsyncAction make_blank1_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e);
        void send_blank1_navi1_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e);
        void send_blank1_navi2_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e);
        winrt::Windows::Foundation::IAsyncAction close_blank1_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e);
    };
}

namespace winrt::appwin_1::factory_implementation
{
    struct MainPage : MainPageT<MainPage, implementation::MainPage>
    {
    };
}
