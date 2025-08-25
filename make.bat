set workspaceDirectory="C:\Users\filippar\sharedVbox"


if exist %workspaceDirectory%\console\ (
    RD /S "%workspaceDirectory%\console"
)

if exist %~dp0build\ (
    RD /S "%~dp0build\"
)

cmake -S %~dp0 -B %~dp0build -G "MinGW Makefiles" -DOS=arm -DCMAKE_PREFIX_PATH="%workspaceDirectory%"  -DCMAKE_BUILD_TYPE=Debug
cmake --build %~dp0build
cmake --install %~dp0build --prefix %workspaceDirectory%
scp C:\Users\filippar\sharedVbox\LiftBiom\console\build\src\Test\console_test root@192.168.1.100: