import { memo } from 'react';
import type { FC } from 'react';
 
import resets from '../../_resets.module.css';
import { BatteryIcon } from './BatteryIcon';
import { CellularConnectionIcon } from './CellularConnectionIcon';
import classes from './WelcomeScreen.module.css';
import { WifiIcon } from './WifiIcon';
 
interface Props {
  className?: string;
}
/* @figmaId 201:183 */
export const WelcomeScreen: FC<Props> = memo(function WelcomeScreen(props = {}) {
  return (
    <div className={`${resets.clapyResets} ${classes.root}`}>
      <div className={classes.rectangle324}></div>
      <div className={classes.seCARity}>SeCARity</div>
      <div className={classes.trackYourCarAndConnectWithFrie}>
        <div className={classes.textBlock}>Track your car and connect with friends all in one place. </div>
        <div className={classes.textBlock2}>Don’t risk losing your car.</div>
      </div>
      <div className={classes.frame31}>
        <div className={classes.lOGIN}>LOG IN</div>
      </div>
      <div className={classes.homeIndicator}>
        <div className={classes.homeIndicator2}></div>
      </div>
      <div className={classes.barsStatusBarsIPhoneLight}>
        <div className={classes.battery}>
          <BatteryIcon className={classes.icon} />
        </div>
        <div className={classes.wifi}>
          <WifiIcon className={classes.icon2} />
        </div>
        <div className={classes.cellularConnection}>
          <CellularConnectionIcon className={classes.icon3} />
        </div>
        <div className={classes.timeStyle}>
          <div className={classes.time}>9:41</div>
        </div>
      </div>
      <div className={classes.sIGNUP}>SIGN UP</div>
    </div>
  );
});