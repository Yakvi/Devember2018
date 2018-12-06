function Get-TimeStamp {
    return Get-Date -DisplayHint Date
}

function Set-Vars {
    If(-Not($Env:__DOTNET_ADD_64BIT)) {
        $Env:__DOTNET_ADD_64BIT="1"
        $Env:__DOTNET_PREFERRED_BITNESS="64"
        $Env:__VSCMD_PREINIT_PATH="C:\WINDOWS\system32;C:\WINDOWS;C:\WINDOWS\System32\Wbem;C:\WINDOWS\System32\WindowsPowerShell\v1.0\;C:\WINDOWS\System32\OpenSSH\;C:\Program Files\Git\cmd;C:\Program Files\dotnet\;C:\Program Files\Microsoft SQL Server\130\Tools\Binn\;C:\Program Files\Microsoft VS Code\bin;C:\Program Files (x86)\NVIDIA Corporation\PhysX\Common;C:\Program Files\nodejs\;C:\ProgramData\chocolatey\bin;C:\Users\Yakvi\AppData\Local\Microsoft\WindowsApps;C:\Program Files\Microsoft VS Code\bin;C:\Users\Yakvi\AppData\Roaming\npm;C:\Users\Yakvi\.dotnet\tools;;h:\handmade\code;"
        $Env:CommandPromptType="Native"
        $Env:DevEnvDir="C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\IDE\"
        $Env:ExtensionSdkDir="C:\Program Files (x86)\Microsoft SDKs\Windows Kits\10\ExtensionSDKs"
        $Env:INCLUDE="C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Tools\MSVC\14.14.26428\ATLMFC\include;C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Tools\MSVC\14.14.26428\include;C:\Program Files (x86)\Windows Kits\NETFXSDK\4.6.1\include\um;C:\Program Files (x86)\Windows Kits\10\include\10.0.17134.0\ucrt;C:\Program Files (x86)\Windows Kits\10\include\10.0.17134.0\shared;C:\Program Files (x86)\Windows Kits\10\include\10.0.17134.0\um;C:\Program Files (x86)\Windows Kits\10\include\10.0.17134.0\winrt;C:\Program Files (x86)\Windows Kits\10\include\10.0.17134.0\cppwinrt"
        $Env:LIB="C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Tools\MSVC\14.14.26428\ATLMFC\lib\x64;C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Tools\MSVC\14.14.26428\lib\x64;C:\Program Files (x86)\Windows Kits\NETFXSDK\4.6.1\lib\um\x64;C:\Program Files (x86)\Windows Kits\10\lib\10.0.17134.0\ucrt\x64;C:\Program Files (x86)\Windows Kits\10\lib\10.0.17134.0\um\x64;"
        $Env:LIBPATH="C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Tools\MSVC\14.14.26428\ATLMFC\lib\x64;C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Tools\MSVC\14.14.26428\lib\x64;C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Tools\MSVC\14.14.26428\lib\x86\store\references;C:\Program Files (x86)\Windows Kits\10\UnionMetadata\10.0.17134.0;C:\Program Files (x86)\Windows Kits\10\References\10.0.17134.0;C:\Windows\Microsoft.NET\Framework64\v4.0.30319;"
        $Env:Path+="C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Tools\MSVC\14.14.26428\bin\HostX64\x64;C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\IDE\VC\VCPackages;C:\Program Files (x86)\Microsoft SDKs\TypeScript\2.8;C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\IDE\CommonExtensions\Microsoft\TestWindow;C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\IDE\CommonExtensions\Microsoft\TeamFoundation\Team Explorer;C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\MSBuild\15.0\bin\Roslyn;C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Team Tools\Performance Tools\x64;C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Team Tools\Performance Tools;C:\Program Files (x86)\Microsoft Visual Studio\Shared\Common\VSPerfCollectionTools\\x64;C:\Program Files (x86)\Microsoft Visual Studio\Shared\Common\VSPerfCollectionTools\;C:\Program Files (x86)\Microsoft SDKs\Windows\v10.0A\bin\NETFX 4.6.1 Tools\x64\;C:\Program Files (x86)\Microsoft SDKs\F#\10.1\Framework\v4.0\;C:\Program Files (x86)\Windows Kits\10\bin\10.0.17134.0\x64;C:\Program Files (x86)\Windows Kits\10\bin\x64;C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\\MSBuild\15.0\bin;C:\Windows\Microsoft.NET\Framework64\v4.0.30319;C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\IDE\;C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\Tools\;"
        $Env:Platform="x64"
        $Env:PROMPT="$P$G"
        $Env:UCRTVersion="10.0.17134.0"
        $Env:UniversalCRTSdkDir="C:\Program Files (x86)\Windows Kits\10\"
        $Env:VCIDEInstallDir="C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\IDE\VC\"
        $Env:VCINSTALLDIR="C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\"
        $Env:VCToolsInstallDir="C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Tools\MSVC\14.14.26428\"
        $Env:VCToolsRedistDir="C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Redist\MSVC\14.14.26405\"
        $Env:VCToolsVersion="14.14.26428"
        $Env:VisualStudioVersion="15.0"
        $Env:VS150COMNTOOLS="C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\Tools\"
        $Env:VSCMD_ARG_app_plat="Desktop"
        $Env:VSCMD_ARG_HOST_ARCH="x64"
        $Env:VSCMD_ARG_TGT_ARCH="x64"
        $Env:VSCMD_VER="15.7.2"
        $Env:VSINSTALLDIR="C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\"
        $Env:WindowsLibPath="C:\Program Files (x86)\Windows Kits\10\UnionMetadata\10.0.17134.0;C:\Program Files (x86)\Windows Kits\10\References\10.0.17134.0"
        $Env:WindowsSDK_ExecutablePath_x64="C:\Program Files (x86)\Microsoft SDKs\Windows\v10.0A\bin\NETFX 4.6.1 Tools\x64\"
        $Env:WindowsSDK_ExecutablePath_x86="C:\Program Files (x86)\Microsoft SDKs\Windows\v10.0A\bin\NETFX 4.6.1 Tools\"
        $Env:WindowsSdkBinPath="C:\Program Files (x86)\Windows Kits\10\bin\"
        $Env:WindowsSdkDir="C:\Program Files (x86)\Windows Kits\10\"
        $Env:WindowsSDKLibVersion="10.0.17134.0\"
        $Env:WindowsSdkVerBinPath="C:\Program Files (x86)\Windows Kits\10\bin\10.0.17134.0\"
        $Env:WindowsSDKVersion="10.0.17134.0\"
        write-Output "Vars set at $(Get-TimeStamp)"
    }
}

function Write-Color([String[]]$Text, [ConsoleColor[]]$Color = "White", [string] $LogFile = "", $TimeFormat = "yyyy-MM-dd HH:mm:ss") {
    # Notes:
    # - TimeFormat https://msdn.microsoft.com/en-us/library/8kb3ddd4.aspx
    
    $DefaultColor = $Color[0]
    if ($Color.Count -ge $Text.Count) {
        for ($i = 0; $i -lt $Text.Length; $i++) { Write-Host $Text[$i] -ForegroundColor $Color[$i] -NoNewLine } 
    }
    else {
        for ($i = 0; $i -lt $Color.Length ; $i++) { Write-Host $Text[$i] -ForegroundColor $Color[$i] -NoNewLine }
        for ($i = $Color.Length; $i -lt $Text.Length; $i++) { Write-Host $Text[$i] -ForegroundColor $DefaultColor -NoNewLine }
    }
    Write-Host
}


function Read-And-Color-Code([String[]]$split, [string]$title = "") {
    foreach ($line in $split) {
        If ($line -match "error") {
            [string]$m = $matches.Values[0].trim()
            $i = $line.IndexOf($m)
            $line.Substring(0, $i) | Write-Host -ForegroundColor "Red" -NoNewline
            $line.Substring($i) | Write-Host -ForegroundColor "Gray" 
        }
        elseif ($line -match "warning") {
            [string]$m = $matches.Values[0].trim()
            $i = $line.IndexOf($m)
            $line.Substring(0, $i) | Write-Host -ForegroundColor "DarkYellow" -NoNewline
            $line.Substring($i) | Write-Host -ForegroundColor "Gray" 
        }
        elseif ($line -match "note") {
            [string]$m = $matches.Values[0].trim()
            $i = $line.IndexOf($m)
            $line.Substring(0, $i) | Write-Host -ForegroundColor "Cyan" -NoNewline
            $line.Substring($i) | Write-Host -ForegroundColor "Gray" 
        }
        else {
            Write-Host $line
        }
    }

    if ($split -match "error") {
        Write-Color -Text $title, " compilation ", "failed ", "at $(Get-TimeStamp)" -Color Cyan, Gray, Red, Gray
    }
}

# NOTE: Compiler params
$compiler = '-MTd', '-nologo'          #Two vars in one line to initialize array; -MTd: creates debug multithreaded executable
$compiler += '-I..\..\iaca-win64\'       #Intel architecture code analyzer path
$compiler += '-fp:fast'                #Floating point behaviour. Precise behaviour usually unnecessary.
$compiler += '-fp:except-'             #Floating point behaviour. Precise behaviour usually unnecessary.
$compiler += '-Gm-'                    #Enables minimal rebuild. For faster compile.
$compiler += '-GR-'                    #Disables run-time type information. For faster compile.
$compiler += '-EHa-'                   #Disables exception handling
$compiler += '-Zo'                     #?
#$compiler += '-Od' #    -Od / -O2      #Disables optimization. Use O2 for release.
$compiler += '-Oi'                     #Generates intrinsic functions. For faster runtime.
$compiler += '-WX'                     #Treats all warnings as errors (except the ones below).
$compiler += '-W4'                     #Displays all warnings (except the ones below).
# NOTE: Ignoring selected warnings:
$compiler += '-wd4201'                 #Nonstandard extension used: nameless struct/union
$compiler += '-wd4100'                 #Unreferenced variable
$compiler += '-wd4189'                 #Local variable initialized but not used
$compiler += '-wd4505'                 #Unreferenced local function
$compiler += '-wd4127'                 #
$compiler += '-wd4302'                 #pointer truncation
$compiler += '-wd4311'                 #truncation
#$compiler += '-wd4838'                 #Conversion from type 1 to type 2 requires a narrowing conversion
#$compiler += '-wd4456'                 #Declaration hides previous local declaration
# NOTE: Preprocessor directives
$compiler += '-DDEVEMBER_DEV=1'   #For debug stuff
$compiler += '-DDEVEMBER_WIN32=1'      #Compiles for Win32
# NOTE: other
$compiler += '-FC'                     #Display full path of source code
$compiler += '-Z7'                     #Generates C 7.0–compatible debugging information.
# NOTE: linker params, go after the source file
$linker = '/link', '-incremental:no'   #Passes linker parameters from here; Disables incremental linking of the linker
$linker += '-opt:ref'                  #Eliminates functions and data that are never referenced
# NOTE: Extra libraries for win32
$32linker = 'user32.lib','gdi32.lib'   #Creates and manipulates the standard elements of the Windows GUI. #Graphics Device Interface, used for primitive drawing functions.
$32linker += 'winmm.lib'               #Provides access to the original WinMM audio API.
# NOTE: Extra parameters for devember.dll linker
$dlllinker = '-Fmdevember', '-LD'      #Creates a map file
$dlllinker2 = '-EXPORT:MainLoop'
# NOTE: Extra parameters for devember.dll linker
$creaturelinker = '-Fmcreature', '-LD'      #Creates a map file
$creaturelinker2 = '-EXPORT:GameGetSoundSamples', '-EXPORT:GameUpdateAndRender'
$creaturelinker2 += '-PDB:creature_' + $(Get-Date -format "HH-mm-ss-ms") + '.pdb'
# NOTE: Optimized linker params
$optimized = '-Fodevember_optimized.obj', '-LD'

#timeout /t 1

Clear
Set-Location ..\build
write-Output ""
write-Output "Compilation started at $(Get-TimeStamp)"
Set-Vars
write-Output ""

#echo "WAITING FOR PDB" > lock.tmp
# OPTIMIZED GAME OBJ
#$optimizedObj = & cl $compiler -O2 -c ..\code\devember_optimized.cpp -Fodevember_optimized -LD
#Read-And-Color-Code -split $optimizedObj -title "optimized game obj" 

# DEVEMBER DLL
$devember = & cl $compiler -Od ..\code\devember.cpp $dlllinker $linker $dlllinker2
Read-And-Color-Code -split $devember -title "devember dll"
#del lock.tmp

# TEST ASSET BUILDER
# $asset = & cl  $compiler -Od -D_CRT_SECURE_NO_WARNINGS ..\code\test_asset_builder.cpp $linker $32linker
# Read-And-Color-Code -split $asset -title "test asset builder" 

# WIN32 PLATFORM LAYER
#$win32devember = & cl $compiler -Od ..\code\win32_devember.cpp -Fmwin32_devember $linker $32linker
Read-And-Color-Code -split $win32devember -title "win32 platform layer"

Write-Host ""
Write-Color -Text "Compilation ", "finished ", "at $(Get-TimeStamp)" -Color Gray, Yellow, Gray

Set-Location ..\code
