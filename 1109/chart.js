const dataset = {
    label: "PYPL",
    backgroundColor: ['#ffd950', '#02bc77', '#28c3d7', '#FF6384','#FF2400','#FFCE00','#86FF00'],//라벨별 컬러설정
    borderColor: '#22252B',
    data: [28.11,17.35,9.48,7.08,6.19,5.47,4.35]
}

const labels=['파이썬','자바','자바스크립트','C#','C/C++','PHP','R']; 
  
const datasets={ datasets:[dataset], labels:labels }
const config1 = {
    type: 'pie',
    data: datasets, 
    options: {
        responsive: false,
        maintainAspectRatio: false, 
        legend: {
            fontColor: 'black',
            display: true,
            fullWidth: true,
            labels: {
                fontColor: 'rgb(0, 0, 0)'
            }
        },
        plugins: {
            labels: {
                render: 'value',
                fontColor: 'black',
                fontSize: 15,
                precision: 2
            }

        }
    }
}
const config2 = {
    type: 'bar',
    data: datasets,
    options: {
        legend: {
            labels: {
                fontColor: 'rgb(255, 255, 255)'
            }
        },
        responsive: false,
    }

}
const config3 = {
    type: 'line',
    data: datasets,
    options: {
      responsive: false,
      plugins: {
        legend: {
          position: 'top',
        },
        }
      }
    }

const pie=document.getElementById('pieChart');
const pieChart = new Chart(pie,config1);
const bar = document.getElementById('barChart')
const barChart = new Chart(bar,config2);
const line = document.getElementById('lineChart')
const lineChart = new Chart(line,config3);