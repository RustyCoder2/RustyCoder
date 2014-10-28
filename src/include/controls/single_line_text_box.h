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

#ifndef CONTROLS_SINGLE_LINE_TEXT_BOX_H
#define CONTROLS_SINGLE_LINE_TEXT_BOX_H

class SingleLineTextBox : public Window
{
    public:
        SingleLineTextBox(const SingleLineTextBox &) = delete;
        SingleLineTextBox & operator=(const SingleLineTextBox &) = delete;

        SingleLineTextBox(HINSTANCE hInstance, HWND hWndParent, const wchar_t * const lpWindowName, int x, int y, int nWidth, int nHeight, int hMenu, DWORD dwExStyle = WS_EX_LEFT, DWORD dwStyle = WS_VISIBLE | WS_CHILD | ES_AUTOHSCROLL);
};

#endif