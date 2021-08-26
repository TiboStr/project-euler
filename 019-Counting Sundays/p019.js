/*
How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
*/

function main() {
    let out = 0;
    for (let year = 1901; year < 2001; year += 1) {
        for (let month = 0; month < 12; month += 1) {
            if (new Date(year, month, 1).getDay() == 0) {
                out += 1;
            }
        }
    }

    console.log(`There were ${out} Sundays that fell on the first of the month during the twentieth century`);
}

main();
