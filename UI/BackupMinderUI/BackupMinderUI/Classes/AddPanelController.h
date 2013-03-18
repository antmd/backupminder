//
//  AddPanelController.h
//  BackupMinderUI
//
//  Created by Christopher Thompson on 8/1/12.
//

// The AddPanelController is a dual purpose dialog
// 1) Add a new backup object
// 2) Edit an existing object
// 
// The default implementation is to add an object
// Nothing special needs to be done to use the Add panel
//
// To create an Edit panel, use the initWithMode:EDIT_PANEL_MODE
// Before you show the panel, set the dictionary to edit by calling
// setBackupDictionary:(NSMutableDictionary*)

#ifndef ADD_PANEL_CONTROLLER_H
#define ADD_PANEL_CONTROLLER_H

#import <Cocoa/Cocoa.h>

enum panelMode_t 
{
    ADD_PANEL_MODE, 
    EDIT_PANEL_MODE, 
    NUM_PANEL_MODES
};

@interface AddPanelController : NSWindowController <NSWindowDelegate>
{    
    // Controls whether we are an Add or Edit panel
    enum panelMode_t m_panelMode;
    
    // Track so I can change to Edit if necessary
    IBOutlet NSButton *m_addButton;
    
    // Track so I can change the icon to a folder
    IBOutlet NSButton *m_backupSourceButton;
    IBOutlet NSButton *m_archiveDestinationButton;
    
    // Text field controls
    IBOutlet NSTextField *m_nameTextField;
    IBOutlet NSTextField *m_backupSourceTextField;
    IBOutlet NSTextField *m_archiveDestinationTextField;
    IBOutlet NSTextField *m_nameContainsTextField;
    IBOutlet NSTextField *m_backupsToLeaveTextField;
    IBOutlet NSTextField *m_warnDaysTextField;
        
    // Name label control
    IBOutlet NSTextField *m_nameLabel;
    
    // The error dialog
    NSAlert *m_errorAlert;
    
    // Track the state of the editted backup
    BOOL currentlyDisabled;
    
    // Open panel default url when no other is available
    NSURL* m_defaultDirectoryURL;
}

// Brief: Initialize the window with a given Add/Edit mode
// Param: window_, the NSWindow object to use
// Param: mode_, the Add/Edit mode to show as
- (id)initWithMode:(enum panelMode_t)mode_;

// Brief: Set the dictionary containing the Backup information
// Param: backupObject_, NSMutableDictionary backup object to use
- (void)setBackupDictionary:(NSMutableDictionary*)backupObject_;

// Brief: Validate the values in the text field
- (BOOL)validateInput;

// Brief: Validate the input and add an object then hide
//        Add or edit a backup item depending on panelMode
// Param: sender_, Id of the sender object
- (IBAction)commit:(id)sender_;

// Brief: Hide the window
// Param: sender_, Id of the sender object
- (IBAction)cancel:(id)sender_;

// Brief: Display an NSOpenPanel window to select the backup source directory
// Param: sender_, Id of the sender object
- (IBAction)selectBackupSource:(id)sender_;

// Brief: Display an NSOpenPanel window to select the archive destination 
//        directory
// Param: sender_, Id of the sender object
- (IBAction)selectArchiveDestination:(id)sender_;

@end

#endif //ADD_PANEL_CONTROLLER_H
