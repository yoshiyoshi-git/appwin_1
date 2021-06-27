#include "pch.h"
#include "MainPage.h"
#include "MainPage.g.cpp"
#include <winrt/Windows.UI.Popups.h>

using namespace winrt;
using namespace Windows::UI::Xaml;

winrt::appwin_1::StringViewModel* pmain_string;

namespace winrt::appwin_1::implementation
{
    //static変数なので実体を生成
    appwin_1::MainPage MainPage::maincurrent{ nullptr };

    MainPage::MainPage()
    {
        InitializeComponent();
        m_mainString = make<appwin_1::implementation::StringViewModel>();

        pmain_string = &m_mainString;

        //maincurrentにthisを代入
        maincurrent = *this;
    }

    appwin_1::StringViewModel MainPage::MainString()
    {
        return m_mainString;
    }

    void MainPage::OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs const& e)
    {
        if (e.Parameter() == nullptr)
            return;

        hstring blank1mes = winrt::unbox_value<winrt::hstring>(e.Parameter());
        if (blank1mes == L"")
            return;

        auto propertyValue{ e.Parameter().as < Windows::Foundation::IPropertyValue>() };

        if (propertyValue.Type() == Windows::Foundation::PropertyType::String)
            main_text().Text(blank1mes);
        else
            main_text().Text(L"文字列じゃないよ！");

        Windows::UI::Popups::MessageDialog msg{ blank1mes,L"とどいたよ～～～" };
        msg.ShowAsync();
    }

    //main_textの変更
    void MainPage::SetMainText(hstring const& data)
    {
        main_text().Text(data);
    }

}

winrt::Windows::Foundation::IAsyncAction winrt::appwin_1::implementation::MainPage::make_blank1_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e)
{
    if (blank1Window == nullptr)
    {
        blank1Window = co_await winrt::Windows::UI::WindowManagement::AppWindow::TryCreateAsync();

        blank1Frame.Navigate(xaml_typename<appwin_1::BlankPage1>());

        winrt::Windows::UI::Xaml::Hosting::ElementCompositionPreview::SetAppWindowContent(blank1Window, blank1Frame);
    }

    co_await blank1Window.TryShowAsync();
    blank1Window.Title(L"Blank1");
}

void winrt::appwin_1::implementation::MainPage::send_blank1_navi1_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e)
{
    blank1Frame.Navigate(xaml_typename<appwin_1::BlankPage1>(), winrt::box_value(L"めいんぺ～～じから　ぶらんく1へ"));
}

void winrt::appwin_1::implementation::MainPage::send_blank1_navi2_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e)
{
    this->Frame().Navigate(xaml_typename<appwin_1::BlankPage1>(), winrt::box_value(L"めいんぺ～～じから　ぶらんく1へ"));
}

winrt::Windows::Foundation::IAsyncAction winrt::appwin_1::implementation::MainPage::close_blank1_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e)
{
    if (blank1Window == nullptr)
        return;

    co_await blank1Window.CloseAsync();
    blank1Window = nullptr;
}
