/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "brave/components/services/bat_ledger/public/cpp/ledger_client_mojo_proxy.h"

namespace bat_ledger {

namespace {

int32_t ToMojomResult(ledger::Result result) {
  return (int32_t)result;
}

ledger::Result ToLedgerResult(int32_t result) {
  return (ledger::Result)result;
}

} // anonymous namespace

LedgerClientMojoProxy::LedgerClientMojoProxy(
    ledger::LedgerClient* ledger_client)
  : ledger_client_(ledger_client) {
}

LedgerClientMojoProxy::~LedgerClientMojoProxy() {
}

void LedgerClientMojoProxy::Test() {
  LOG(ERROR) << __PRETTY_FUNCTION__;
  ledger_client_->Test();
}

void LedgerClientMojoProxy::LoadLedgerState(LoadLedgerStateCallback callback) {
  LOG(ERROR) << __PRETTY_FUNCTION__;
  load_ledger_state_callback_ = std::move(callback);
  ledger_client_->LoadLedgerState(this);
}

void LedgerClientMojoProxy::OnLedgerStateLoaded(ledger::Result result,
                                                const std::string& data) {
  LOG(ERROR) << __PRETTY_FUNCTION__;
  std::move(load_ledger_state_callback_).Run(ToMojomResult(result), data);
}

void LedgerClientMojoProxy::LoadPublisherState(
    LoadPublisherStateCallback callback) {
  LOG(ERROR) << __PRETTY_FUNCTION__;
  load_publisher_state_callback_ = std::move(callback);
  ledger_client_->LoadPublisherState(this);
}

void LedgerClientMojoProxy::OnPublisherStateLoaded(ledger::Result result,
                                                   const std::string& data) {
  LOG(ERROR) << __PRETTY_FUNCTION__;
  std::move(load_publisher_state_callback_).Run(ToMojomResult(result), data);
}

void LedgerClientMojoProxy::LoadPublisherList(
    LoadPublisherListCallback callback) {
  LOG(ERROR) << __PRETTY_FUNCTION__;
  load_publisher_list_callback_ = std::move(callback);
  ledger_client_->LoadPublisherList(this);
}

void LedgerClientMojoProxy::OnPublisherListLoaded(ledger::Result result,
                                                  const std::string& data) {
  LOG(ERROR) << __PRETTY_FUNCTION__;
  std::move(load_publisher_list_callback_).Run(ToMojomResult(result), data);
}

void LedgerClientMojoProxy::SaveLedgerState(
    const std::string& ledger_state, SaveLedgerStateCallback callback) {
  LOG(ERROR) << __PRETTY_FUNCTION__;
  save_ledger_state_callback_ = std::move(callback);
  ledger_client_->SaveLedgerState(ledger_state, this);
}

void LedgerClientMojoProxy::OnLedgerStateSaved(ledger::Result result) {
  LOG(ERROR) << __PRETTY_FUNCTION__;
  std::move(save_ledger_state_callback_).Run(ToMojomResult(result));
}

void LedgerClientMojoProxy::SavePublisherState(
    const std::string& publisher_state, SavePublisherStateCallback callback) {
  LOG(ERROR) << __PRETTY_FUNCTION__;
  save_publisher_state_callback_ = std::move(callback);
  ledger_client_->SavePublisherState(publisher_state, this);
}

void LedgerClientMojoProxy::OnPublisherStateSaved(ledger::Result result) {
  LOG(ERROR) << __PRETTY_FUNCTION__;
  std::move(save_publisher_state_callback_).Run(ToMojomResult(result));
}

void LedgerClientMojoProxy::SavePublishersList(
    const std::string& publishers_list, SavePublishersListCallback callback) {
  LOG(ERROR) << __PRETTY_FUNCTION__;
  save_publishers_list_callback_ = std::move(callback);
  ledger_client_->SavePublishersList(publishers_list, this);
}

void LedgerClientMojoProxy::OnPublishersListSaved(ledger::Result result) {
  LOG(ERROR) << __PRETTY_FUNCTION__;
  std::move(save_publishers_list_callback_).Run(ToMojomResult(result));
}

} // namespace bat_ledger
