// Copyright (c) 2011-2016 The Bitcoin Core developers
// Copyright (c) 2017-2021 The Raven Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef RAVEN_QT_GUICONSTANTS_H
#define RAVEN_QT_GUICONSTANTS_H

/* Milliseconds between model updates */
static const int MODEL_UPDATE_DELAY = 250;

/* AskPassphraseDialog -- Maximum passphrase length */
static const int MAX_PASSPHRASE_SIZE = 1024;

/* RavenGUI -- Size of icons in status bar */
static const int STATUSBAR_ICONSIZE = 16;

static const bool DEFAULT_SPLASHSCREEN = true;

/* Invalid field background style */
#define STYLE_INVALID "background:#FF8080; border: 1px solid lightgray; padding: 0px;"
#define STYLE_VALID "border: 1px solid lightgray; padding: 0px;"

/* Transaction list -- unconfirmed transaction */
#define COLOR_UNCONFIRMED QColor(128, 128, 128)
/* Transaction list -- negative amount */
#define COLOR_NEGATIVE QColor(255, 0, 0)
/* Transaction list -- bare address (without label) */
#define COLOR_BAREADDRESS QColor(140, 140, 140)
/* Transaction list -- TX status decoration - open until date */
#define COLOR_TX_STATUS_OPENUNTILDATE QColor(64, 64, 255)
/* Transaction list -- TX status decoration - danger, tx needs attention */
#define COLOR_TX_STATUS_DANGER QColor(200, 100, 100)
/* Transaction list -- TX status decoration - default color */
#define COLOR_BLACK QColor(0, 0, 0)
/* Widget Background color - default color */
#define COLOR_WHITE QColor(255, 255, 255)

#define COLOR_WALLETFRAME_SHADOW QColor(0,0,0,71)

/* M593 Ecuador identity: Pacific navy, equatorial gold and Andean teal. */
#define COLOR_LABELS QColor("#0F766E")

/** LIGHT MODE */
/* Background color, very light gray */
#define COLOR_BACKGROUND_LIGHT QColor("#fbfbfe")
/* Equatorial gold */
#define COLOR_DARK_ORANGE QColor("#C8942E")
/* Warm highland sunlight */
#define COLOR_LIGHT_ORANGE QColor("#E4BC62")
/* Pacific navy */
#define COLOR_DARK_BLUE QColor("#071F2B")
/* Andean teal */
#define COLOR_LIGHT_BLUE QColor("#0F766E")
/* Ravencoin asset text */
#define COLOR_ASSET_TEXT QColor(255, 255, 255)
/* Ravencoin shadow color - light mode */
#define COLOR_SHADOW_LIGHT QColor("#e1e6f3")
/* Toolbar not selected text color */
#define COLOR_TOOLBAR_NOT_SELECTED_TEXT QColor("#B9CFCA")
/* Toolbar selected text color */
#define COLOR_TOOLBAR_SELECTED_TEXT COLOR_WHITE
/* Send entries background color */
#define COLOR_SENDENTRIES_BACKGROUND QColor("#fbfbfe")


/** DARK MODE */
/* Widget background color, dark mode */
#define COLOR_WIDGET_BACKGROUND_DARK QColor("#0B1720")
/* Ravencoin shadow color - dark mode */
#define COLOR_SHADOW_DARK QColor("#020B10")
/* Ravencoin Light blue - dark mode - dark mode */
#define COLOR_LIGHT_BLUE_DARK QColor("#102B31")
/* Ravencoin Dark blue - dark mode - dark mode */
#define COLOR_DARK_BLUE_DARK QColor("#06161E")
/* Pricing widget background color */
#define COLOR_PRICING_WIDGET QColor("#0A2028")
/* Ravencoin dark mode administrator background color */
#define COLOR_ADMIN_CARD_DARK COLOR_BLACK
/* Ravencoin dark mode regular asset background color */
#define COLOR_REGULAR_CARD_DARK_BLUE_DARK_MODE QColor("#08242B")
/* Ravencoin dark mode regular asset background color */
#define COLOR_REGULAR_CARD_LIGHT_BLUE_DARK_MODE QColor("#0F3B3A")
/* Toolbar not selected text color */
#define COLOR_TOOLBAR_NOT_SELECTED_TEXT_DARK_MODE QColor("#8FB5AE")
/* Toolbar selected text color */
#define COLOR_TOOLBAR_SELECTED_TEXT_DARK_MODE QColor("#FFF7E2")
/* Send entries background color dark mode */
#define COLOR_SENDENTRIES_BACKGROUND_DARK QColor("#0B1720")


/* Ravencoin label color as a string */
#define STRING_LABEL_COLOR "color: #E4BC62"
#define STRING_LABEL_COLOR_WARNING "color: #FF8080"








/* Tooltips longer than this (in characters) are converted into rich text,
   so that they can be word-wrapped.
 */
static const int TOOLTIP_WRAP_THRESHOLD = 80;

/* Maximum allowed URI length */
static const int MAX_URI_LENGTH = 255;

/* QRCodeDialog -- size of exported QR Code image */
#define QR_IMAGE_SIZE 300

/* Number of frames in spinner animation */
#define SPINNER_FRAMES 36

#define QAPP_ORG_NAME "M593"
#define QAPP_ORG_DOMAIN "m593.org"
#define QAPP_APP_NAME_DEFAULT "M593-Wallet"
#define QAPP_APP_NAME_TESTNET "M593-Wallet-testnet"

/* Default third party browser urls */
#define DEFAULT_THIRD_PARTY_BROWSERS ""

/* Default IPFS viewer */
#define DEFAULT_IPFS_VIEWER "https://ipfs.io/ipfs/%s"

#endif // RAVEN_QT_GUICONSTANTS_H
