object Form1: TForm1
  Left = 515
  Top = 425
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = #1048#1075#1088#1072' "'#1059#1075#1072#1076#1072#1081' '#1095#1080#1089#1083#1086'"'
  ClientHeight = 442
  ClientWidth = 650
  Color = clInactiveCaption
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 192
    Top = 16
    Width = 257
    Height = 29
    BiDiMode = bdLeftToRight
    Caption = #1048#1075#1088#1072' "'#1059#1075#1072#1076#1072#1081' '#1095#1080#1089#1083#1086'"'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentBiDiMode = False
    ParentFont = False
  end
  object Label2: TLabel
    Left = 112
    Top = 200
    Width = 159
    Height = 24
    BiDiMode = bdLeftToRight
    Caption = #1042#1074#1077#1076#1077#1085#1085#1099#1077' '#1095#1080#1089#1083#1072
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentBiDiMode = False
    ParentFont = False
  end
  object Label3: TLabel
    Left = 392
    Top = 80
    Width = 87
    Height = 16
    BiDiMode = bdLeftToRight
    Caption = #1042#1072#1096#1077' '#1095#1080#1089#1083#1086
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold, fsUnderline]
    ParentBiDiMode = False
    ParentFont = False
  end
  object Label4: TLabel
    Left = 136
    Top = 80
    Width = 121
    Height = 16
    BiDiMode = bdLeftToRight
    Caption = #1047#1072#1076#1091#1084#1072#1090#1100' '#1095#1080#1089#1083#1086
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold, fsUnderline]
    ParentBiDiMode = False
    ParentFont = False
  end
  object Label5: TLabel
    Left = 392
    Top = 200
    Width = 95
    Height = 24
    BiDiMode = bdLeftToRight
    Caption = #1055#1086#1076#1089#1082#1072#1079#1082#1080
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentBiDiMode = False
    ParentFont = False
  end
  object Button1: TButton
    Left = 392
    Top = 136
    Width = 89
    Height = 49
    Caption = #1042#1074#1077#1089#1090#1080' '#1095#1080#1089#1083#1086
    TabOrder = 0
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 376
    Top = 104
    Width = 121
    Height = 21
    TabOrder = 1
    OnKeyPress = PhoneKeyPress
  end
  object Edit2: TEdit
    Left = 128
    Top = 104
    Width = 137
    Height = 21
    TabOrder = 2
    OnKeyPress = PhoneKeyPress
  end
  object Button2: TButton
    Left = 136
    Top = 136
    Width = 113
    Height = 49
    Caption = #1057#1086#1079#1076#1072#1090#1100' '#1085#1086#1074#1086#1077' '#1095#1080#1089#1083#1086
    TabOrder = 3
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 264
    Top = 384
    Width = 89
    Height = 49
    Caption = #1042#1099#1093#1086#1076
    TabOrder = 4
    OnClick = Button3Click
  end
  object Memo1: TMemo
    Left = 104
    Top = 240
    Width = 185
    Height = 129
    TabOrder = 5
    OnKeyPress = Memo1KeyPress
  end
  object Memo2: TMemo
    Left = 344
    Top = 240
    Width = 185
    Height = 129
    TabOrder = 6
    OnKeyPress = Memo1KeyPress
  end
  object Timer1: TTimer
    Interval = 3000
    OnTimer = Timer1Timer
    Left = 616
  end
end
