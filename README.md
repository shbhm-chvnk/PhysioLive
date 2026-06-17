# PhysioLive: An IoT-Based Physiotherapy Monitoring System

## Overview
PhysioLive is a Real-Time Physiotherapy Monitoring Platform that integrates IoT sensors, live telemetry streaming, and interactive analytics to track patient rehabilitation exercises. The system enables therapists to monitor movement data, generate reports, and detect abnormal motion patterns during therapy sessions.

## Key Features
- Real-Time Patient Monitoring
- Motion Sensor Data Tracking
- Live Analytics Dashboard
- Automated Alert Generation
- IoT-Based Rehabilitation Insights

## Project Structure
 ```
PhysioLive/
├── src/
│   ├── physio_dashboard.py
│   ├── import_serial.py
│   ├── dashboard.html
│   ├── index.html
│   ├── style.css
│   ├── about.html
│   └── telemetry_server/
│       └── telemetry_server[v1a, v1b, v2a, v2b].ino
├── data/
│   ├── live_data.csv
│   └── alert_log.csv
├── assets/
│   ├── exercise_guide[LAVL, LAHLE, RHWUD, RHHWUE].png
│   ├── about[abt1, abt2, abt3].jpg
│   ├── alert.mp3
│   └── logo[linkedin, physiolive].png
└── README.md
 ```

## Technology Stack
- Python
- Pandas
- Plotly
- Streamlit
- IoT Sensors & Telemetry

## Dashboard Insights
- Live Motion Tracking
- Accelerometer & Gyroscope Monitoring
- Threshold-Based Alerts
- Rehabilitation Progress Analysis
- PDF Session Report Generation

## Getting Started
1. Clone the repository.
2. Install dependencies: `pip install -r requirements.txt` using the provided [requirements.txt](https://drive.google.com/file/d/1QqBd3kOlSIe9JapFYWU7MONh8kv-_5tU/view?usp=sharing).
3. Run the dashboard: `streamlit run src/physio_dashboard.py`
4. Access the dashboard on Physiolive website.
5. Explore real-time monitoring & rehabilitation insights.

## Applications
- Physiotherapy Clinics
- Remote Patient Monitoring
- Sports Rehabilitation
- Movement Analytics
- Healthcare Research
