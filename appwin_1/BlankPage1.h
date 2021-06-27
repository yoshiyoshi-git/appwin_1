#pragma once

#include "BlankPage1.g.h"

#include "MainPage.h"

namespace winrt::appwin_1::implementation
{
    struct BlankPage1 : BlankPage1T<BlankPage1>
    {
        BlankPage1();

        //mainFrame追加
        Windows::UI::Xaml::Controls::Frame mainFrame{};

        void OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs const& e) ;
        void send_Mainpage_navi_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e);
        void send_Mainpage_global_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e);
        void send_Mainpage_mem_func_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e);
    };
}

namespace winrt::appwin_1::factory_implementation
{
    struct BlankPage1 : BlankPage1T<BlankPage1, implementation::BlankPage1>
    {
    };
}
