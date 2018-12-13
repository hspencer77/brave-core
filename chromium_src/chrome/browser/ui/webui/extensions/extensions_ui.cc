/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "brave/grit/brave_generated_resources.h"
#include "content/public/browser/web_ui_data_source.h"

// Forward declarations needed due to extensions_ui.cc being patched with this
// function name.
namespace extensions {
namespace {
void BraveAddLocalizedStrings(content::WebUIDataSource* html_source);
} // namespace
} // namespace extensions

#include "../../../../../../chrome/browser/ui/webui/extensions/extensions_ui.cc"

namespace extensions {

namespace {

void BraveAddLocalizedStrings(content::WebUIDataSource* html_source) {
  html_source->AddLocalizedString("moreExtensions",
    IDS_MD_EXTENSIONS_BRAVE_MORE_EXTENSIONS);
}

} // namespace

} // namespace extensions
