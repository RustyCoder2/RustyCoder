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

#include "stdafx.h"
#include "file_dialog_events.h"

void FileDialogEvents::SetData(void *data)
{
    this->data = data;
}

IFACEMETHODIMP FileDialogEvents::QueryInterface(REFIID riid, void** ppv)
{
    static const QITAB qit[] = {QITABENT(FileDialogEvents, IFileDialogEvents), QITABENT(FileDialogEvents, IFileDialogControlEvents), {0}};
    return QISearch(this, qit, riid, ppv);
}

IFACEMETHODIMP_(ULONG) FileDialogEvents::AddRef()
{
    return InterlockedIncrement(&reference_count);
}

IFACEMETHODIMP_(ULONG) FileDialogEvents::Release()
{
    return InterlockedDecrement(&reference_count);
}

IFACEMETHODIMP FileDialogEvents::OnFileOk(IFileDialog * /* pfd */)
{
    return E_NOTIMPL;
}

IFACEMETHODIMP FileDialogEvents::OnFolderChange(IFileDialog * /* pfd */)
{
    return E_NOTIMPL;
}

IFACEMETHODIMP FileDialogEvents::OnFolderChanging(IFileDialog * /* pfd */, IShellItem * /* psiFolder */)
{
    return E_NOTIMPL;
}

IFACEMETHODIMP FileDialogEvents::OnOverwrite(IFileDialog * /* pfd */, IShellItem * /* psi */, FDE_OVERWRITE_RESPONSE * /* pResponse */)
{
    return E_NOTIMPL;
}

IFACEMETHODIMP FileDialogEvents::OnSelectionChange(IFileDialog * /* pfd */)
{
    return E_NOTIMPL;
}

IFACEMETHODIMP FileDialogEvents::OnShareViolation(IFileDialog * /* pfd */, IShellItem * /* psi */, FDE_SHAREVIOLATION_RESPONSE * /* pResponse */)
{
    return E_NOTIMPL;
}

IFACEMETHODIMP FileDialogEvents::OnTypeChange(IFileDialog * /* pfd */)
{
    return E_NOTIMPL;
}

IFACEMETHODIMP FileDialogEvents::OnButtonClicked(IFileDialogCustomize * /* pfdc */, DWORD /* dwIDCtl */)
{
    return E_NOTIMPL;
}

IFACEMETHODIMP FileDialogEvents::OnCheckButtonToggled(IFileDialogCustomize * /* pfdc */, DWORD /* dwIDCtl */, BOOL /* bChecked */)
{
    return E_NOTIMPL;
}

IFACEMETHODIMP FileDialogEvents::OnControlActivating(IFileDialogCustomize * /* pfdc */, DWORD /* dwIDCtl */)
{
    return E_NOTIMPL;
}

IFACEMETHODIMP FileDialogEvents::OnItemSelected(IFileDialogCustomize * /* pfdc */, DWORD /* dwIDCtl */, DWORD /* dwIDItem */)
{
    return E_NOTIMPL;
}

FileDialogEvents::~FileDialogEvents()
{
    assert(reference_count == 0);
}