#include "WebUI.h"
#include <Arduino.h>

WebUI::WebUI() {
    // Constructor implementation
}

WebUI::~WebUI() {
    // Destructor implementation
}

void WebUI::init() {
    // Implementation of WebUI initialization
}

void WebUI::init(const char* dir, const char** files) {
    // Implementation of WebUI initialization with parameters
}

void WebUI::loop() {
    // Implementation of WebUI loop
}

const char* WebUI::getDashboardHtml() {
    static const char* html = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>RuntimeOS Dashboard</title>
    <style>
        :root {
            --primary-color: #4361ee;
            --secondary-color: #3a0ca3;
            --success-color: #4cc9f0;
            --warning-color: #f72585;
            --dark-color: #1d3557;
            --light-color: #f8f9fa;
            --gray-color: #6c757d;
            --border-radius: 8px;
            --box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);
        }
        
        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
            font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
        }
        
        body {
            background-color: #f5f7fb;
            color: #333;
            line-height: 1.6;
        }
        
        .container {
            max-width: 1200px;
            margin: 0 auto;
            padding: 20px;
        }
        
        header {
            background-color: var(--primary-color);
            color: white;
            padding: 15px 20px;
            border-radius: var(--border-radius);
            box-shadow: var(--box-shadow);
            margin-bottom: 20px;
            display: flex;
            justify-content: space-between;
            align-items: center;
        }
        
        .logo {
            display: flex;
            align-items: center;
            gap: 10px;
        }
        
        .logo-icon {
            font-size: 24px;
        }
        
        nav ul {
            display: flex;
            list-style: none;
            gap: 15px;
        }
        
        nav a {
            color: white;
            text-decoration: none;
            padding: 8px 12px;
            border-radius: var(--border-radius);
            transition: background-color 0.3s;
        }
        
        nav a:hover, nav a.active {
            background-color: rgba(255, 255, 255, 0.2);
        }
        
        .dashboard-grid {
            display: grid;
            grid-template-columns: repeat(auto-fit, minmax(300px, 1fr));
            gap: 20px;
            margin-bottom: 20px;
        }
        
        .card {
            background-color: white;
            border-radius: var(--border-radius);
            box-shadow: var(--box-shadow);
            padding: 20px;
            transition: transform 0.3s;
        }
        
        .card:hover {
            transform: translateY(-5px);
        }
        
        .card h2 {
            color: var(--dark-color);
            margin-bottom: 15px;
            font-size: 1.2em;
        }
        
        .status-indicator {
            display: inline-block;
            width: 12px;
            height: 12px;
            border-radius: 50%;
            margin-right: 8px;
        }
        
        .status-online {
            background-color: #4ade80;
        }
        
        .status-offline {
            background-color: #f87171;
        }
        
        .status-warning {
            background-color: #fbbf24;
        }
        
        .stats-grid {
            display: grid;
            grid-template-columns: repeat(auto-fit, minmax(200px, 1fr));
            gap: 15px;
            margin-bottom: 20px;
        }
        
        .stat-card {
            background-color: white;
            border-radius: var(--border-radius);
            box-shadow: var(--box-shadow);
            padding: 15px;
            text-align: center;
        }
        
        .stat-value {
            font-size: 2em;
            font-weight: bold;
            color: var(--primary-color);
        }
        
        .stat-label {
            color: var(--gray-color);
            font-size: 0.9em;
        }
        
        .section {
            background-color: white;
            border-radius: var(--border-radius);
            box-shadow: var(--box-shadow);
            padding: 20px;
            margin-bottom: 20px;
        }
        
        .section h2 {
            color: var(--dark-color);
            margin-bottom: 15px;
            padding-bottom: 10px;
            border-bottom: 2px solid var(--light-color);
        }
        
        table {
            width: 100%;
            border-collapse: collapse;
        }
        
        th, td {
            padding: 12px;
            text-align: left;
            border-bottom: 1px solid var(--light-color);
        }
        
        th {
            background-color: var(--light-color);
            font-weight: 600;
        }
        
        tr:hover {
            background-color: #f8f9fa;
        }
        
        .btn {
            display: inline-block;
            padding: 10px 20px;
            background-color: var(--primary-color);
            color: white;
            text-decoration: none;
            border-radius: var(--border-radius);
            border: none;
            cursor: pointer;
            transition: background-color 0.3s;
        }
        
        .btn:hover {
            background-color: var(--secondary-color);
        }
        
        footer {
            text-align: center;
            padding: 20px;
            color: var(--gray-color);
            font-size: 0.9em;
            margin-top: 20px;
        }
        
        @media (max-width: 768px) {
            .container {
                padding: 10px;
            }
            
            header {
                flex-direction: column;
                gap: 10px;
                text-align: center;
            }
            
            nav ul {
                flex-wrap: wrap;
                justify-content: center;
            }
            
            .dashboard-grid {
                grid-template-columns: 1fr;
            }
        }
    </style>
</head>
<body>
    <div class="container">
        <header>
            <div class="logo">
                <span class="logo-icon">🔧</span>
                <h1>RuntimeOS Dashboard</h1>
            </div>
            <nav>
                <ul>
                    <li><a href="#" class="active">Dashboard</a></li>
                    <li><a href="#">Modules</a></li>
                    <li><a href="#">Logs</a></li>
                    <li><a href="#">Settings</a></li>
                    <li><a href="#">About</a></li>
                </ul>
            </nav>
        </header>
        
        <div class="dashboard-grid">
            <div class="card">
                <h2>System Status</h2>
                <p>RuntimeOS is running <span class="status-indicator status-online"></span> online</p>
                <p>WiFi: Connected to RuntimeOS-AP</p>
                <p>IP Address: 192.168.4.1</p>
            </div>
            
            <div class="card">
                <h2>Resource Usage</h2>
                <p>CPU: <span class="status-indicator status-online"></span> 45%</p>
                <p>Memory: <span class="status-indicator status-warning"></span> 78% (3.1 MB)</p>
                <p>Storage: <span class="status-indicator status-online"></span> 62% (128 KB)</p>
            </div>
            
            <div class="card">
                <h2>Network</h2>
                <p>Connected Devices: 3</p>
                <p>Bandwidth: 15 Mbps</p>
                <p>Signal Strength: -62 dBm</p>
            </div>
        </div>
        
        <div class="stats-grid">
            <div class="stat-card">
                <div class="stat-value">24</div>
                <div class="stat-label">Active Modules</div>
            </div>
            <div class="stat-card">
                <div class="stat-value">156</div>
                <div class="stat-label">System Events</div>
            </div>
            <div class="stat-card">
                <div class="stat-value">87%</div>
                <div class="stat-label">Uptime</div>
            </div>
            <div class="stat-card">
                <div class="stat-value">12</div>
                <div class="stat-label">Active Connections</div>
            </div>
        </div>
        
        <div class="section">
            <h2>System Modules</h2>
            <table>
                <thead>
                    <tr>
                        <th>Name</th>
                        <th>Status</th>
                        <th>Type</th>
                        <th>Version</th>
                    </tr>
                </thead>
                <tbody>
                    <tr>
                        <td>WiFi Manager</td>
                        <td><span class="status-indicator status-online"></span> Online</td>
                        <td>Network</td>
                        <td>v1.2.0</td>
                    </tr>
                    <tr>
                        <td>Storage Manager</td>
                        <td><span class="status-indicator status-online"></span> Online</td>
                        <td>Storage</td>
                        <td>v1.0.0</td>
                    </tr>
                    <tr>
                        <td>Plugin Manager</td>
                        <td><span class="status-indicator status-warning"></span> Warning</td>
                        <td>System</td>
                        <td>v1.1.0</td>
                    </tr>
                    <tr>
                        <td>Power Manager</td>
                        <td><span class="status-indicator status-online"></span> Online</td>
                        <td>System</td>
                        <td>v1.3.0</td>
                    </tr>
                </tbody>
            </table>
        </div>
        
        <footer>
            <p>RuntimeOS v0.1.0 | Built for embedded systems</p>
        </footer>
    </div>
</body>
</html>
    )rawliteral";
    
    return html;
}
